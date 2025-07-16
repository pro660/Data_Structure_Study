/* 2. 여러 자리 정수의 수식 계산 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;
/* isp와 icp 배열 -- 인덱스는 연산자
lparen, rparen, plus, minus, times, divide, mod, eos, operand의 우선순위 값 */
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
char expr[MAX_EXPR_SIZE];

precedence stack[MAX_STACK_SIZE];
int top = -1;
// boolean isempty (stack) ::= top < 0;
// boolean isfull (stack) ::= top >= max_stack_size - 1;
void stackFull()
{
	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
}
precedence stackEmpty()
{
	//precedence dummy = { '\0' };
	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
	//return dummy;
}
void push(precedence item)
{ // 전역 stack에 item을 삽입
	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
		stackFull();
	stack[++top] = item;
}
precedence pop()
{ // stack의 최상의 원소를 반환.
	if (top == -1) // 스택이 있는지 확인.
		return stackEmpty(); // 오류 Key를 반환.
	return stack[top--];
}

int eval_stack[MAX_STACK_SIZE];
int eval_top = -1;
void eval_push(int item)
{ // 전역 stack에 item을 삽입
	if (eval_top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
		stackFull();
	eval_stack[++eval_top] = item;
}
int eval_pop()
{ // stack의 최상의 원소를 반환.
	if (eval_top == -1) // 스택이 있는지 확인.
		return stackEmpty(); // 오류 Key를 반환.
	return eval_stack[eval_top--];
}

void printToken(precedence token)
{
	switch (token)
	{
	case lparen: printf("("); break;
	case rparen: printf(")"); break;
	case plus: printf("+"); break;
	case minus: printf("-"); break;
	case divide: printf("/"); break;
	case times: printf("*"); break;
	case mod: printf("%%"); break;
	}
}

char* context = NULL; // 전역 또는 static으로 유지
char* expr_ptr; // 전역 변수로 expr 복사본 가리킴

precedence getToken(char* symbol, int* value)
{
	char* token;

	// 처음 호출이면 expr_ptr에서 자르고, 이후엔 NULL 사용
	if (context == NULL)
		token = strtok_s(expr_ptr, " ", &context);
	else
		token = strtok_s(NULL, " ", &context);

	if (token == NULL) {
		context = NULL;
		return eos;
	}

	*symbol = token[0];

	if (isdigit(*symbol) || (*symbol == '-' && isdigit(token[1])))
	{
		*value = atoi(token);
		return operand;
	}

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
	default:
		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
	}
}
void postfix(void)
{	
	char symbol;
	precedence token;
	int value;

	expr_ptr = expr; // 전역 expr 사용
	context = NULL;

	top = 0; // eos를 스택에 삽입한다.
	stack[0] = eos;
	while ((token = getToken(&symbol, &value)) != eos)
	{	// 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴.
		if (token == operand)
			printf("%d ", value);
		else if (token == rparen)
		{
			while (stack[top] != lparen)
			{
				printToken(pop());
				printf(" ");
			}
			pop(); // 완쪽 괄호를 버린다.
		}
		else
		{	// symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴.
			while (isp[stack[top]] >= icp[token])
			{
				printToken(pop());
				printf(" ");
			}
			push(token);
		}
	}
	while ((token = pop()) != eos)
	{
		printToken(token);
		printf(" ");
	}
	printf("\n");
}
int eval(void)
{	
	precedence token;
	char symbol;
	int op1, op2;
	int value;

	eval_top = -1;
	token = getToken(&symbol, &value);
	while (token != eos)
	{
		if (token == operand)
			eval_push(value);
		else
		{
			/* 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함. */
			op2 = eval_pop();
			op1 = eval_pop();
			switch (token)
			{
			case plus: eval_push(op1 + op2);
				break;
			case minus: eval_push(op1 - op2);
				break;
			case times: eval_push(op1 * op2);
				break;
			case divide: eval_push(op1 / op2);
				break;
			case mod: eval_push(op1 % op2);
			}
		}
		token = getToken(&symbol, &value);
	}
	return eval_pop(); // 결과를 반환.
}
int main()
{
	printf("중위 표기식을 입력하세요.(공백으로 구분.) : ");
	fgets(expr, MAX_EXPR_SIZE, stdin); // 공백 포함 입력 받기
	printf("후위 표기식: ");
	postfix();
	printf("\n후위 표기식을 입력하세요 (공백으로 구분): ");
	fgets(expr, MAX_EXPR_SIZE, stdin);
	printf("후위 표기식 연산 결과: %d\n", eval());
}