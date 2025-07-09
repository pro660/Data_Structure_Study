// 1. 수식의 계산(후위식표기)
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef enum {
	lparen, rparen, plus, minus, times, 
	divide, mod, eos, operand
}precedence;
char expr[100];
int stack[MAX_STACK_SIZE];
int top = -1;
int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };
void push(int item)
{
	if (top >= MAX_STACK_SIZE - 1) {
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
	switch (token) 
	{
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
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(':return lparen;
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
	for (token = getToken(&symbol, &n); token != eos; 
		token = getToken(&symbol, &n))
	{
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		printToken(token);
	printf("\n");
}
int main(void)
{
	printf("중위식을 입력하세요: ");
	scanf_s("%s", expr, (unsigned)_countof(expr));
	printf("후위식: ");
	postfix();
}