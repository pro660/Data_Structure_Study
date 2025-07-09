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
#define MAX_STACK_SIZE 100
typedef enum {
	lparen, rparen, plus, minus, times,
	divide, mod, eos, operand
} precedence;
char expr[100];
char prefixExpr[100];
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
	switch (token) {
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
	switch (*symbol) {
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
	int n = strlen(expr) - 1;
	int p = 0;
	top = 0;
	stack[0] = eos;
	prefixExpr[0] = '\0';
	for (token = getToken(&symbol, &n); 
		token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
			prefixExpr[p++] = symbol;
		else if (token == rparen) 
		{
			while (stack[top] != lparen)
				prefixExpr[p++] = tokenToChar(pop());
			pop(); 
		}
		else
		{
			while (isp[stack[top]] > icp[token])
				prefixExpr[p++] = tokenToChar(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		prefixExpr[p++] = tokenToChar(token);
	for (int i = 0; i < p / 2; ++i) {
		char temp = prefixExpr[i];
		prefixExpr[i] = prefixExpr[p - i - 1];
		prefixExpr[p - i - 1] = temp;
	}
	prefixExpr[p] = '\0';
	printf("%s\n", prefixExpr);
}
int evalPrefix() 
{
	int evalStack[MAX_STACK_SIZE];
	int evalTop = -1;
	int i = strlen(prefixExpr) - 1;
	while (i >= 0) {
		char symbol = prefixExpr[i--];
		if (symbol >= '0' && symbol <= '9')
		{
			evalStack[++evalTop] = symbol - '0';
		}
		else 
		{
			int op2 = evalStack[evalTop--];
			int op1 = evalStack[evalTop--];
			switch (symbol) {
			case '+': evalStack[++evalTop] = op1 + op2; break;
			case '-': evalStack[++evalTop] = op1 - op2; break;
			case '*': evalStack[++evalTop] = op1 * op2; break;
			case '/': evalStack[++evalTop] = op1 / op2; break;
			case '%': evalStack[++evalTop] = op1 % op2; break;
			}
		}
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