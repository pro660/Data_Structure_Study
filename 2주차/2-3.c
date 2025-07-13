// 3. 1, 2 를 전위식표기로 구현
// 3.1 전위식 표기
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef enum {
    lparen, rparen, plus, minus, times,
    divide, mod, eos, operand
} precedence;
char expr[100];
int stack[MAX_STACK_SIZE];
int top = -1;
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };
void push(int item)
{
    if (top >= MAX_STACK_SIZE - 1) 
    {
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    stack[++top] = item;
}
int pop() 
{
    if (top == -1) 
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return stack[top--];
}
void printToken(precedence token)
{
    switch (token) {
    case plus: printf("+"); break;
    case minus: printf("-"); break;
    case times: printf("*"); break;
    case divide: printf("/"); break;
    case mod: printf("%%"); break;
    case lparen: printf("("); break;
    case rparen: printf(")"); break;
    }
}
precedence getToken(char* symbol, int* n)
{
    *symbol = expr[(*n)--];
    switch (*symbol) {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '/': return divide;
    case '*': return times;
    case '%': return mod;
    case '\0': return eos;
    default: return operand;
    }
}

void prefix(void)
{
    char symbol;
    precedence token;
    int n = strlen(expr) - 1;  
    top = 0;
    stack[0] = eos;
    for (token = getToken(&symbol, &n); token != eos;
        token = getToken(&symbol, &n)) 
    {
        if (token == operand)
            printf("%c", symbol);
        else if (token == lparen)  
        {
            while (stack[top] != rparen)
                printToken(pop());
            pop();  
        }
        else
        {
            while (isp[stack[top]] > icp[token])  
                printToken(pop());
            push(token);
        }
    }
    while ((token = pop()) != eos)
        printToken(token);
    printf("\n");
}
int main(void) {
    printf("중위식을 입력하세요: ");
    scanf_s("%s", expr, (unsigned)_countof(expr));
    printf("전위식: ");
    prefix();
}

// 3.2 전위식 계산
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_SIZE 1000
typedef enum {
    lparen, rparen, plus, minus, times,
    divide, mod, eos, operand
} precedence;
char expr[100];
char prefixExpr[300];
int stack[MAX_STACK_SIZE];
int top = -1;
int isp[] = { 0, 0, 13, 13, 12, 12, 12, 0 };
int icp[] = { 20, 20, 13, 13, 12, 12, 12, 0 };
void push(int item) 
{
    if (top >= MAX_STACK_SIZE - 1) 
    {
        printf("스택이 가득 찼습니다.\n");
        exit(1);
    }
    stack[++top] = item;
}
int pop() {
    if (top == -1)
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    return stack[top--];
}
char tokenToChar(precedence token)
{
    switch (token)
    {
    case plus: return '+'; 
    case minus: return '-'; 
    case times: return '*';
    case divide: return '/'; 
    case mod: return '%'; 
    default: return '?';
    }
}
precedence getToken(char* symbol, int* n) 
{
    *symbol = expr[(*n)--];
    switch (*symbol)
    {
    case ')': return lparen;
    case '(': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '/': return divide;
    case '*': return times;
    case '%': return mod;
    case '\0': return eos;
    default: return operand;
    }
}
void toPrefix(void)
{
    char symbol;
    precedence token;
    int n = (int)strlen(expr) - 1;
    prefixExpr[0] = '\0';
    top = 0;
    stack[0] = eos;
    while (n >= 0) {
        if (isdigit(expr[n])) 
        {
            int end = n;
            while (n >= 0 && isdigit(expr[n])) n--;
            int start = n + 1;
            strncat_s(prefixExpr, sizeof(prefixExpr),
                &expr[start], end - start + 1);
            int len = (int)strlen(prefixExpr);
            prefixExpr[len] = ' ';
            prefixExpr[len + 1] = '\0';
        }
        else 
        {
            token = getToken(&symbol, &n);
            if (token == rparen) 
            {
                while (stack[top] != lparen)
                {
                    int len = (int)strlen(prefixExpr);
                    prefixExpr[len] = tokenToChar(pop());
                    prefixExpr[len + 1] = ' ';
                    prefixExpr[len + 2] = '\0';
                }
                pop();
            }
            else 
            {
                while (isp[stack[top]] > icp[token])
                {
                    int len = (int)strlen(prefixExpr);
                    prefixExpr[len] = tokenToChar(pop());
                    prefixExpr[len + 1] = ' ';
                    prefixExpr[len + 2] = '\0';
                }
                push(token);
            }
        }
    }
    while ((token = pop()) != eos)
    {
        int len = (int)strlen(prefixExpr);
        prefixExpr[len] = tokenToChar(token);
        prefixExpr[len + 1] = ' ';
        prefixExpr[len + 2] = '\0';
    }
    char temp[300]; strcpy_s(temp, sizeof(temp), prefixExpr);
    char result[300] = "";
    int plen = (int)strlen(temp), t = 0;
    int s = plen - 1;
    while (s >= 0)
    {
        while (s >= 0 && temp[s] == ' ') s--;
        int e = s;
        while (s >= 0 && temp[s] != ' ') s--;
        int wordLen = e - s;
        if (wordLen > 0) 
        {
            strncat_s(result, sizeof(result), temp + s + 1, wordLen);
            int rlen = (int)strlen(result);
            result[rlen] = ' ';
            result[rlen + 1] = '\0';
        }
    }
    int rlen = (int)strlen(result);
    if (rlen > 0 && result[rlen - 1] == ' ') 
        result[rlen - 1] = '\0'; 
    strcpy_s(prefixExpr, sizeof(prefixExpr), result);
    printf("%s\n", prefixExpr);
}
int evalPrefix() 
{
    int evalStack[MAX_STACK_SIZE] = { 0 };
    int evalTop = -1;
    int len = (int)strlen(prefixExpr);
    int i = len - 1;
    while (i >= 0) {
        if (isspace(prefixExpr[i]))
        {
            i--;
            continue;
        }
        if (isdigit(prefixExpr[i]))
        {
            int start = i;
            while (i >= 0 && isdigit(prefixExpr[i])) i--;
            char numStr[20] = { 0 };
            int numLen = start - i;
            strncpy_s(numStr, sizeof(numStr),
                &prefixExpr[i + 1], numLen);
            numStr[numLen] = '\0';
            if (evalTop + 1 >= MAX_STACK_SIZE) 
            {
                printf("오류: 피연산자 스택 오버플로우!\n");
                exit(1);
            }
            evalStack[++evalTop] = atoi(numStr);
        }
        else
        {
            if (evalTop < 1) 
            {
                printf("오류: 피연산자가 부족합니다!\n");
                exit(1);
            }
            int op1 = evalStack[evalTop--];
            int op2 = evalStack[evalTop--];
            int res = 0;
            switch (prefixExpr[i]) 
            {
            case '+': res = op1 + op2; break;
            case '-': res = op1 - op2; break;
            case '*': res = op1 * op2; break;
            case '/': res = op1 / op2; break;
            case '%': res = op1 % op2; break;
            default:
                printf("지원하지 않는 연산자: %c\n", prefixExpr[i]);
                exit(1);
            }
            evalStack[++evalTop] = res;
            i--;
        }
    }
    if (evalTop != 0) 
    {
        printf("오류: 계산 후 스택에 값이 여러 개 남음!\n");
        exit(1);
    }
    return evalStack[evalTop];
}

int main(void) {
    printf("중위식을 입력하세요: ");
    scanf_s("%s", expr, (unsigned)_countof(expr));
    printf("전위식: ");
    toPrefix();
    printf("계산 결과: %d\n", evalPrefix());
}
