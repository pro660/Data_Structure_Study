/* 중위식->후위식->계산 (여러 자리 수 처리 가능) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
char token2char(precedence token);
void printToken(precedence token);
int pop();
void push(int);
void stackFull();
void stackEmpty();
void EnterNot();

//전역 변수 선언
#define MAX_EXPR_SIZE 200
#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top;
char expr[MAX_EXPR_SIZE];
int current_number; // getToken이 읽은 숫자를 저장하는 전역 변수

int main(){
    printf("Enter the infix notation (end with '~') : ");
    EnterNot();
    postfix(); // postfix 안에서 제목과 결과를 출력

    printf("Result => %d\n", eval());
    return 0;
}

/** 후위 표기식을 계산하는 함수 */
int eval(void){
    precedence token;
    char symbol; // getToken의 인자로만 사용됨
    int op1, op2;
    int n=0; /* 수식 스트링을 위한 카운터 */
    top = -1;

    // expr 에는 postfix()에 의해 후위표기식이 저장되어 있음
    token = getToken(&symbol, &n);

    while(token != eos){
        if(token == operand)
            // getToken이 읽은 온전한 숫자를 push
            push(current_number);
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

/** 여러 자리 숫자를 포함한 토큰을 인식하는 함수 */
precedence getToken(char *symbol, int *n){
    // 1. 공백 건너뛰기
    while(expr[*n] == ' ' || expr[*n] == '\t') {
        (*n)++;
    }

    *symbol = expr[*n];

    // 2. 숫자인지 확인
    if(isdigit(*symbol)) {
        current_number = 0;
        while(isdigit(expr[*n])) { // 여러자리를 한 묶음으로 생각하여 current_number로 저장
            current_number = current_number * 10 + (expr[*n] - '0');
            (*n)++;
        }
        return operand;
    }

    // 3. 연산자 또는 괄호 확인
    *symbol = expr[(*n)++];
    switch(*symbol){
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': // 문자열 끝
        case '~':  // 사용자 입력 끝
            return eos;
        default :  // 그 외의 경우 (잘못된 입력 등)
            return eos;
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
    char symbol;
    precedence token;
    int n = 0, i = 0;
    char tmp[MAX_EXPR_SIZE] = {0}; // 임시 후위식 저장 배열

    top = 0;
    stack[0] = eos; // 스택의 바닥을 표시

    printf("Postfix notation : ");

    for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)){
        if(token == operand){
            // 숫자를 공백과 함께 출력하고 임시 배열에 저장
            printf("%d ", current_number);
            i += sprintf(tmp + i, "%d ", current_number);
        }
        else if(token == rparen){
            while(stack[top] != lparen){
                precedence op = pop();
                printToken(op);
                putchar(' ');
                tmp[i++] = token2char(op);
                tmp[i++] = ' ';
            }
            pop(); // 왼쪽 괄호를 버린다
        }
        else{
            while(isp[stack[top]] >= icp[token]){
                precedence op = pop();
                printToken(op);
                putchar(' ');
                tmp[i++] = token2char(op);
                tmp[i++] = ' ';
            }
            push(token);
        }
    }
    while((token=pop()) != eos){
        printToken(token);
        putchar(' ');
        tmp[i++] = token2char(token);
        tmp[i++] = ' ';
    }
    printf("\n");

    // 완성된 후위표기식을 전역 변수 expr에 복사하여 eval()이 사용하도록 함
    strcpy(expr, tmp);
}

void EnterNot(void){
    char ch;
    int i = 0;
    while(scanf("%c", &ch) == 1 && ch != '~' && i < MAX_EXPR_SIZE -1){
        if(ch != '\n') expr[i++] = ch;
    }
    expr[i] = '\0';   // 널 종료
}

void push(int item){
    if(top >= MAX_STACK_SIZE-1) {
        stackFull();
    }
    stack[++top] = item;
}

int pop(){
    if(top == -1) {
        // stackEmpty()는 프로그램을 종료시키므로, 계산 완료 후 마지막 pop은 예외처리
        return 0;
    }
    return stack[top--];
}

void stackFull(){
    fprintf(stderr, "Stack is full, cannot push.\n");
    exit(EXIT_FAILURE);
}

void stackEmpty(){
    fprintf(stderr, "Stack is empty, cannot pop.\n");
    exit(EXIT_FAILURE);
}