/* 3. 1을 전위식표기로 구현 */

#include <stdio.h>
#include <stdlib.h>
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
	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
		stackFull();
	eval_stack[++eval_top] = item;
}
int eval_pop()
{ // stack의 최상의 원소를 반환.
	if (eval_top == -1) // 스택이 있는지 확인.
		return stackEmpty(); // 오류 Key를 반환.
	return eval_stack[eval_top--];
}

char getSymbol(precedence token)
{
	switch (token)
	{
	case plus: return '+';
	case minus: return '-';
	case times: return '*';
	case divide: return '/';
	case mod: return '%';
	case lparen: return '(';
	case rparen: return ')';
	default: return '?'; // 오류 방지로 임시
	}
}
precedence getToken(char* symbol, int* n)
{	/* 프로그램 3.14: 입력 스트링으로부터 토큰을 가져오는 함수.
	다음 토큰을 취한다.
	symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 함수 이름으로 반환된다. */
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
	default:
		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
	}
}

void reverse(char* str)
{	// 수식을 뒤집는 함수.
	int i, len = strlen(str);
	for (i = 0; i < len / 2; i++) {
		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

void swapParentheses(char* str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') str[i] = ')';
		else if (str[i] == ')') str[i] = '(';
	}
}

void prefix()
{	// 전위 표기식: 중위 수식을 뒤집어, 후위 수식 변환 후, 다시 뒤집으면 전위 수식.
	char original[MAX_EXPR_SIZE];
	strcpy_s(original, expr);

	reverse(original); // 수식 뒤집기.

	swapParentheses(original); // 괄호 반전.

	// expr에 변환된 수식 넣고 후위로 변환
	strcpy_s(expr, original);
	printf("변환된 (뒤집힌 + 괄호교체된) 중위 수식: %s\n", expr);
	printf("전위 표기식: ");

	// 후위 표기식을 만들고, 출력 순서를 반대로 하면 전위 표기식.
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	char result[MAX_EXPR_SIZE];
	int res_index = 0;

	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
		if (token == operand) {
			result[res_index++] = symbol;
		}
		else if (token == rparen) {
			while (stack[top] != lparen)
				result[res_index++] = getSymbol(pop());
			pop(); // 왼쪽 괄호 제거
		}
		else {
			while (isp[stack[top]] >= icp[token])
				result[res_index++] = getSymbol(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		result[res_index++] = getSymbol(token);

	result[res_index] = '\0';

	reverse(result); // 후위 표기식을 전위 표기식으로.

	for (int i = 0; i < res_index; i++)
	{
		printf("%c", result[i]);
	}
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = strlen(expr) - 1;  // 오른쪽부터 시작.
	eval_top = -1;  // eval_stack 초기화.

	while (n >= 0)
	{
		symbol = expr[n--];

		switch (symbol)
		{
		case '+': token = plus; break;
		case '-': token = minus; break;
		case '*': token = times; break;
		case '/': token = divide; break;
		case '%': token = mod; break;
		default: token = operand;
		}

		if (token == operand)
			eval_push(symbol - '0');  // char 타입 숫자 int 변환.
		else
		{
			op1 = eval_pop();  // 왼쪽.
			op2 = eval_pop();  // 오른쪽.

			switch (token)
			{
			case plus: eval_push(op1 + op2); break;
			case minus: eval_push(op1 - op2); break;
			case times: eval_push(op1 * op2); break;
			case divide: eval_push(op1 / op2); break;
			case mod: eval_push(op1 % op2); break;
			}
		}
	}
	return eval_pop();  // 최종 결과.
}
int main()
{
	printf("중위 표기식을 입력하세요. : ");
	scanf_s("%s", expr, (unsigned)_countof(expr));

	prefix();

	printf("\n전위 표기식을 입력하세요. : ");
	scanf_s("%s", expr, (unsigned)_countof(expr));
	printf("전위 표기식 연산 결과: %d\n", eval());
}