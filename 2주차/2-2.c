// 2. 여러 자리 정수의 수식 계산
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
char postfixExpr[300];
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
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
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
void postfix(void)
{
    char symbol;
    precedence token;
    int n = 0;
    top = 0;
    stack[0] = eos;
    postfixExpr[0] = '\0';
    while (expr[n] != '\0')
    {
        if (isdigit(expr[n]))
        {
            int start = n;
            while (isdigit(expr[n])) n++;
            strncat_s(postfixExpr, sizeof(postfixExpr), &expr[start], n - start);
            int len = (int)strlen(postfixExpr);
            postfixExpr[len] = ' ';
            postfixExpr[len + 1] = '\0';
        }
        else
        {
            token = getToken(&symbol, &n);
            if (token == rparen)
            {
                while (stack[top] != lparen) 
                {
                    int len = (int)strlen(postfixExpr);
                    postfixExpr[len] = tokenToChar(pop());
                    postfixExpr[len + 1] = ' ';
                    postfixExpr[len + 2] = '\0';
                }
                pop(); 
            }
            else
            {
                while (isp[stack[top]] >= icp[token]) 
                {
                    int len = (int)strlen(postfixExpr);
                    postfixExpr[len] = tokenToChar(pop());
                    postfixExpr[len + 1] = ' ';
                    postfixExpr[len + 2] = '\0';
                }
                push(token);
            }
        }
    }
    while ((token = pop()) != eos)
    {
        int len = (int)strlen(postfixExpr);
        postfixExpr[len] = tokenToChar(token);
        postfixExpr[len + 1] = ' ';
        postfixExpr[len + 2] = '\0';
    }
    printf("%s\n", postfixExpr);
}
int eval(void)
{
    int evalStack[MAX_STACK_SIZE] = { 0 };
    int evalTop = -1;
    char* ptr = postfixExpr;
    while (*ptr)
    {
        if (isdigit(*ptr))
        {
            int num = 0;
            while (isdigit(*ptr))
            {
                num = num * 10 + (*ptr - '0');
                ptr++;
            }
            evalStack[++evalTop] = num;
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/' || *ptr == '%')
        {
            int op2 = evalStack[evalTop--];
            int op1 = evalStack[evalTop--];
            switch (*ptr)
            {
            case '+': evalStack[++evalTop] = op1 + op2; break;
            case '-': evalStack[++evalTop] = op1 - op2; break;
            case '*': evalStack[++evalTop] = op1 * op2; break;
            case '/': evalStack[++evalTop] = op1 / op2; break;
            case '%': evalStack[++evalTop] = op1 % op2; break;
            }
        }
        ptr++;
    }
    return evalStack[evalTop];
}
int main(void)
{
    printf("중위식을 입력하세요: ");
    scanf_s("%s", expr, (unsigned)sizeof(expr));
    printf("후위식: ");
    postfix();
    printf("계산 결과: %d\n", eval());
}