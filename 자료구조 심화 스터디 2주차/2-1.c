/* 중위식->후위식->계산 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 타입 정의
typedef enum { /** 토큰에 직접적인 이름을 부여하기 위한 enum 타입 */
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

// 우선순위 선언
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};

// 함수 선언
int eval(void);
precedence getToken(char*, int*);
void postfix(void); 
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
    printf("Postfix notation : ");
    postfix();

    printf("Result => %d\n", eval());
    return 0; 
}

/** 후위 표기식을 계산하는 함수 */
int eval(void){
    precedence token;
    char symbol;
    int op1, op2;
    int n=0; /* 수식 스트링을 위한 카운터 */
    top = -1;

    token = getToken(&symbol, &n);
    
    while(token != eos){
        if(token == operand)
            push(symbol - '0'); // 문자형 정수를 실제 정수형으로 변환
        else{
            /* 두 피연산자를 삭제하여 연산을 수행 한 후, 그 결과를 스택에 삽입함 */
            op2 = pop();
            op1 = pop();

            switch(token){
                case plus: push(op1+op2); break;
                case minus: push(op1-op2); break;
                case times: push(op1*op2); break;
                case divide: push(op1/op2); break;
                case mod: push(op1%op2); break;
                default: break;
            }
        }
        token = getToken(&symbol, &n);   
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

void postfix(void){
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
            putchar(symbol);
            tmp[i++] = symbol;
        }
        else if(token == rparen){
        /* 왼쪽 괄호가 나올 때 까지 토큰들을 제거해서 출력시킴 */
            while(stack[top] != lparen){
                precedence op = pop();
                printToken(op);
                tmp[i++] = token2char(op);
            }
            pop(); /* 왼쪽 괄호를 버린다 */
        }
        else{
            /* symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴 */
            while(isp[stack[top]] >= icp[token]){
                precedence op = pop();
                printToken(op);
                tmp[i++] = token2char(op);
            }
            push(token);
        }
    }
    while((token=pop())!=eos){
        printToken(token);
        tmp[i++] = token2char(token);
    }
    printf("\n");

    tmp[i] = '\0';
    strcpy(expr, tmp);
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