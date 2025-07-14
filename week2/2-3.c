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
    int n = strlen(expr) - 1; // 오른쪽부터 왼쪽으로
    top = -1;

    while(n >= 0){
        symbol = expr[n];

        // 공백 무시
        if(symbol == ' '){
            n--;
            continue;
        }

        // 숫자면 여러 자리 숫자 추출
        if(symbol >= '0' && symbol <= '9'){
            int num = 0;
            int base = 1;
            // 오른쪽부터 왼쪽으로 읽으므로 base 사용
            while(n >= 0 && expr[n] >= '0' && expr[n] <= '9'){
                num += (expr[n] - '0') * base;
                base *= 10;
                n--;
            }
            push(num);
        } else {
            // 연산자 처리
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
            if(token != operand){
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
                n--;
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
    char symbol;
    precedence token;
    int n = 0, i = 0;
    char tmp[MAX_EXPR_SIZE];

    top = 0;
    stack[0] = eos;
    while (expr[n] != '\0') {
        // 숫자(여러 자리) 처리
        if (expr[n] >= '0' && expr[n] <= '9') {
            int start = n;
            while (expr[n] >= '0' && expr[n] <= '9') n++;
            // 숫자 복사
            for (int j = start; j < n; j++) {
                tmp[i++] = expr[j];
            }
            tmp[i++] = ' ';
        }
        // 괄호 및 연산자 처리
        else {
            symbol = expr[n++];
            switch(symbol){
                case '(': 
                    while(stack[top] != rparen){
                        precedence op = pop();
                        tmp[i++] = token2char(op);
                        tmp[i++] = ' ';
                    }
                    pop();
                    break;
                case ')':
                    push(rparen);
                    break;
                case '+': case '-': case '*': case '/': case '%':
                {
                    precedence token;
                    switch(symbol){
                        case '+': token=plus; break;
                        case '-': token=minus; break;
                        case '*': token=times; break;
                        case '/': token=divide; break;
                        case '%': token=mod; break;
                    }
                    while(isp[stack[top]] > icp[token]){
                        precedence op = pop();
                        tmp[i++] = token2char(op);
                        tmp[i++] = ' ';
                    }
                    push(token);
                    break;
                }
                default:
                    break;
            }
        }
    }
    while((token=pop())!=eos){
        tmp[i++] = token2char(token);
        tmp[i++] = ' ';
    }
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