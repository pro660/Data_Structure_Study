/* 전위표기식의 계산 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 타입 정의
typedef enum { /** 토큰에 직접적인 이름을 부여하기 위한 enum 타입 */
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

// 우선순위 선언
int isp[] = {0,0,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};

// 함수 선언
int eval(void);
precedence getToken(char*, int*);
void prefix(void); 
void printToken(precedence token);
int pop();
void push(int);
void stackFull();
void stackEmpty();
void EnterNot();

//전역 변수 선언
#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top;
char expr[MAX_EXPR_SIZE];

int main(){ 
    printf("Enter the infix notation(end with '~') : ");
    EnterNot();

    strrev(expr);

    printf("prefix notation : ");
    prefix();

    printf("Result => %d\n", eval());
    return 0; 
}

/** 후위 표기식을 계산하는 함수 */
int eval(void){
    precedence token;
    char symbol;
    int op1, op2;
    int n = strlen(expr) -1; /* 수식 스트링을 위한 카운터 */
    top = -1;
    
    while(n >= 0){
        symbol = expr[n--]; /* 오른쪽부터 왼쪽으로 문자를 가져옴 */

        switch(symbol){
            case '(': token=lparen; break;
            case ')': token=rparen; break;
            case '+': token=plus; break;
            case '-': token=minus; break;
            case '*': token=times; break;
            case '/': token=divide; break;
            case '%': token=mod; break;
            case '\0': token=eos; break;
            default : token=operand; break;
        }

        if(token == operand)
            push(symbol - '0'); // 피연산자는 스택에 push
        else{
            /* 두 피연산자를 pop하여 연산을 수행 한 후, 그 결과를 스택에 삽입함 */
            op1 = pop();
            op2 = pop();

            switch(token){
                case plus: push(op1+op2); break;
                case minus: push(op1-op2); break;
                case times: push(op1*op2); break;
                case divide: push(op1/op2); break;
                case mod: push(op1%op2); break;
                default: break;
            }
        }
    }
    return pop();
}

/** 문자 변수와 0이 저장되어 있는 변수의 주소를 불러와서 연산자를 확인하는 함수 */
precedence getToken(char *symbol, int *n){
    *symbol = expr[(*n)++];
    
    switch(*symbol){
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case '\0': return eos;
        default : return operand;
    }  
}

char token2char(precedence token){
    switch(token){
        case lparen:  return '(';
        case rparen:  return ')';
        case plus:    return '+';
        case minus:   return '-';
        case times:   return '*';
        case divide:  return '/';
        case mod:     return '%';
        default:      return '?';
    }
}

void printToken(precedence token) {
    putchar(token2char(token));
}

void prefix(void){
    /* 수식을 후위표기식으로 출력한다. 수식 스트링, 스택, top은 전역적이다. */
    char symbol;
    precedence token;
    int n = 0, i = 0;

    char tmp[MAX_EXPR_SIZE];

    top = 0;
    /* eos에 스택을 삽입한다 */
    stack[0] = eos;
    for(token = getToken(&symbol, &n); token!=eos; token = getToken(&symbol, &n)){
        if(token == operand){
            tmp[i++] = symbol;
        }
        else if(token == rparen)    
            push(token);
        else if(token == lparen){
            while(stack[top] != rparen){ // 뒤집힌 수식의 '(', 즉 원래의 ')'
                precedence op = pop();
                tmp[i++] = token2char(op);
            }
            pop(); /* 오른쪽 괄호를 버린다 */
        }
        else{ // rparen과 일반 연산자 처리
            // 스택 top의 우선순위가 현재 토큰보다 높거나 같으면 pop
            // (rparen의 isp는 0이므로, lparen을 만날 때까지 절대 pop되지 않음)
            while(isp[stack[top]] > icp[token]){
                precedence op = pop();
                tmp[i++] = token2char(op);
            }
            push(token);
        }
    }
    while((token=pop())!=eos){
        tmp[i++] = token2char(token);
    }
    printf("\n");

    tmp[i] = '\0';
    strrev(tmp);
    strcpy(expr, tmp);

    printf("%s\n", expr);
}

void EnterNot(void){
    char ch;
    int i = 0;
    while(scanf("%c", &ch) == 1 && ch != '~'){
        if(ch != '\n') expr[i++] = ch;
    }
    expr[i] = '\0';   // 널 종료
}

void push(int item){ //top이 사이즈-1보다 크거나 같으면 Full, 따라서 종료 or Full이 아닐 시 item 삽입

	if(top>=MAX_STACK_SIZE-1) {
		stackFull();
    }
	stack[++top] = item;
}

int pop(){
	if(top==-1) {
		stackEmpty();
    }
	return stack[top--];
}

void stackFull(){
	fprintf(stderr, "stack is Full already");
	exit(1);
}

void stackEmpty(){
	fprintf(stderr, "stack is Empty already");
	exit(1);
}