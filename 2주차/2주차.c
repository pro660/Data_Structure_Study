/*
1. 수식의 계산(후위식표기)
2. 여러 자리 정수의 수식 계산
3. 1, 2를 전위식표기로 구현
4. 미로 찾기(교재 그림 3.8~3.10, 프로그램 3.12)
*/

/* 1. 수식의 계산(후위식 표기) */

//#include <stdio.h>
//#include <stdlib.h>
//#define max_stack_size 100
//typedef struct
//{
//	char key;
//} element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//// Boolean IsEmpty (Stack) ::= top < 0;
//// Boolean IsFull (Stack) ::= top >= MAX_STACK_SIZE - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//	return dummy;
//}
//void push(element item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	stack[++top] = item;
//}
//element pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return stack[top--];
//}
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
///* isp와 icp 배열 -- 인덱스는 연산자
//lparen, rparen, plus, minus, times, divide, mod, eos, operand의 우선순위 값 */
//int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
//int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
//void postfix(void)
//{	/* 프로그램 3.15: 중위 표기를 후위 표기로 변환하는 함수.
//	수식을 후위 표기식으로 출력한다.
//	수식 스트링, 스택, top은 전역적이다. */
//	char symbol;
//	precedence token;
//	int n = 0;
//	int top = 0; // eos를 스택에 삽입한다.
//	stack[0] = eos;
//	for (token == getToken(&symbol, &n); token != eos; token == getToken(&symbol, &n))
//	{	// 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴.
//		if (token == operand)
//			printf("%c", symbol);
//		else if (token == rparen)
//		{
//			while (stack[top] != lparen)
//				printToken(pop());
//			pop(); // 완쪽 괄호를 버린다.
//		}
//		else
//		{	// symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴.
//			while (isp[stack[top]] >= icp[token])
//				printToken(pop());
//			push(token);
//		}
//	}
//	while ((token = pop()) != eos)
//		printToken(token);
//	printf("\n");
//}
//precedence getToken(char* symbol, int* n)
//{	/* 프로그램 3.14: 입력 스트링으로부터 토큰을 가져오는 함수.
//	다음 토큰을 취한다.
//	symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 함수 이름으로 반환된다. */
//	*symbol = expr[(*n)++];
//	switch (*symbol)
//	{
//	case '(': return lparen;
//	case ')': return rparen;
//	case '+': return plus;
//	case '-': return minus;
//	case '/': return divide;
//	case '*': return times;
//	case ' ': return eos;
//	default:
//		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
//	}
//}
//int eval(void)
//{	/* 프로그램 3.14: 후위 표기식을 계산하는 함수.
//	전역 변수로 되어 있는 후위 표기식 expr을 연산한다.
//	'\0'은 수식의 끝을 나타낸다.
//	stack과 top은 전역변수이다.
//	함수 getToken은 토큰의 타입과 문자 심벌을 반환한다.
//	피연산자는 한 문자로 된 숫자임을 가정한다. */
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int n = 0; // 수식 스트링을 위한 카운터.
//	int top = -1;
//	token = getToken(&symbol, &n);
//	while (token != eos)
//	{
//		if (token == operand)
//			push(symbol - '0'); // 스택 삽입.
//		else
//		{
//			/* 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함. */
//			op2 = pop();
//			op1 = pop();
//			switch (token)
//			{
//			case plus: push(op1 + op2);
//				break;
//			case minus: push(op1 - op2);
//				break;
//			case times: push(op1 * op2);
//				break;
//			case divide: push(op1 / op2);
//				break;
//			case mod: push(op1 % op2);
//			}
//		}
//		token = getToken(&symbol, &n);
//	}
//	return pop(); // 결과를 반환.
//}
//int main()
//{
//	
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 100
//#define MAX_EXPR_SIZE 100
//
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
///* isp와 icp 배열 -- 인덱스는 연산자
//lparen, rparen, plus, minus, times, divide, mod, eos, operand의 우선순위 값 */
//int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
//int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
//char expr[MAX_EXPR_SIZE];
//
//precedence stack[MAX_STACK_SIZE];
//int top = -1;
//// boolean isempty (stack) ::= top < 0;
//// boolean isfull (stack) ::= top >= max_stack_size - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//}
//precedence stackEmpty()
//{
//	//precedence dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//	//return dummy;
//}
//void push(precedence item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	stack[++top] = item;
//}
//precedence pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return stack[top--];
//}
//
//int eval_stack[MAX_STACK_SIZE];
//int eval_top = -1;
//void eval_push(int item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	eval_stack[++top] = item;
//}
//int eval_pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return eval_stack[top--];
//}
//
//void printToken(precedence token)
//{
//	switch (token)
//	{
//	case lparen: printf("("); break;
//	case rparen: printf(")"); break;
//	case plus: printf("+"); break;
//	case minus: printf("-"); break;
//	case divide: printf("/"); break;
//	case times: printf("*"); break;
//	case mod: printf("%%"); break;
//	}
//}
//precedence getToken(char* symbol, int* n)
//{	/* 프로그램 3.14: 입력 스트링으로부터 토큰을 가져오는 함수.
//	다음 토큰을 취한다.
//	symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 함수 이름으로 반환된다. */
//	*symbol = expr[(*n)++];
//	switch (*symbol)
//	{
//	case '(': return lparen;
//	case ')': return rparen;
//	case '+': return plus;
//	case '-': return minus;
//	case '/': return divide;
//	case '*': return times;
//	case '%': return mod;
//	case '\0': return eos;
//	default:
//		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
//	}
//}
//void postfix(void)
//{	/* 프로그램 3.15: 중위 표기를 후위 표기로 변환하는 함수.
//	수식을 후위 표기식으로 출력한다.
//	수식 스트링, 스택, top은 전역적이다. */
//	char symbol;
//	precedence token;
//	int n = 0;
//	top = 0; // eos를 스택에 삽입한다.
//	stack[0] = eos;
//	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
//	{	// 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴.
//		if (token == operand)
//			printf("%c", symbol);
//		else if (token == rparen)
//		{
//			while (stack[top] != lparen)
//				printToken(pop());
//			pop(); // 완쪽 괄호를 버린다.
//		}
//		else
//		{	// symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴.
//			while (isp[stack[top]] >= icp[token])
//				printToken(pop());
//			push(token);
//		}
//	}
//	while ((token = pop()) != eos)
//		printToken(token);
//	printf("\n");
//}
//int eval(void)
//{	/* 프로그램 3.14: 후위 표기식을 계산하는 함수.
//	전역 변수로 되어 있는 후위 표기식 expr을 연산한다.
//	'\0'은 수식의 끝을 나타낸다.
//	stack과 top은 전역변수이다.
//	함수 gettoken은 토큰의 타입과 문자 심벌을 반환한다.
//	피연산자는 한 문자로 된 숫자임을 가정한다. */
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int n = 0; // 수식 스트링을 위한 카운터.
//	top = 0;
//	token = getToken(&symbol, &n);
//	while (token != eos)
//	{
//		if (token == operand)
//			eval_push(symbol - '0'); // 스택 삽입.
//		else
//		{
//			/* 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함. */
//			op2 = eval_pop();
//			op1 = eval_pop();
//			switch (token)
//			{
//			case plus: eval_push(op1 + op2);
//				break;
//			case minus: eval_push(op1 - op2);
//				break;
//			case times: eval_push(op1 * op2);
//				break;
//			case divide: eval_push(op1 / op2);
//				break;
//			case mod: eval_push(op1 % op2);
//			}
//		}
//		token = getToken(&symbol, &n);
//	}
//	return eval_pop(); // 결과를 반환.
//}
//int main()
//{
//	printf("중위 표기식을 입력하세요. : ");
//	scanf_s("%s", expr, (unsigned)_countof(expr));
//	printf("후위 표기식: ");
//	postfix();
//	printf("\n후위 표기식을 입력하세요. : ");
//	scanf_s("%s", expr, (unsigned)_countof(expr));
//	printf("후위 표기식 연산 결과: %d\n", eval());
//}

/* 2. 여러 자리 정수의 수식 계산 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//#define MAX_EXPR_SIZE 100
//
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
///* isp와 icp 배열 -- 인덱스는 연산자
//lparen, rparen, plus, minus, times, divide, mod, eos, operand의 우선순위 값 */
//int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
//int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
//char expr[MAX_EXPR_SIZE];
//
//precedence stack[MAX_STACK_SIZE];
//int top = -1;
//// boolean isempty (stack) ::= top < 0;
//// boolean isfull (stack) ::= top >= max_stack_size - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//}
//precedence stackEmpty()
//{
//	//precedence dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//	//return dummy;
//}
//void push(precedence item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	stack[++top] = item;
//}
//precedence pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return stack[top--];
//}
//
//int eval_stack[MAX_STACK_SIZE];
//int eval_top = -1;
//void eval_push(int item)
//{ // 전역 stack에 item을 삽입
//	if (eval_top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	eval_stack[++eval_top] = item;
//}
//int eval_pop()
//{ // stack의 최상의 원소를 반환.
//	if (eval_top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return eval_stack[eval_top--];
//}
//
//void printToken(precedence token)
//{
//	switch (token)
//	{
//	case lparen: printf("("); break;
//	case rparen: printf(")"); break;
//	case plus: printf("+"); break;
//	case minus: printf("-"); break;
//	case divide: printf("/"); break;
//	case times: printf("*"); break;
//	case mod: printf("%%"); break;
//	}
//}
//
//char* context = NULL; // 전역 또는 static으로 유지
//char* expr_ptr; // 전역 변수로 expr 복사본 가리킴
//
//precedence getToken(char* symbol, int* value)
//{
//	char* token;
//
//	// 처음 호출이면 expr_ptr에서 자르고, 이후엔 NULL 사용
//	if (context == NULL)
//		token = strtok_s(expr_ptr, " ", &context);
//	else
//		token = strtok_s(NULL, " ", &context);
//
//	if (token == NULL) {
//		context = NULL;
//		return eos;
//	}
//
//	*symbol = token[0];
//
//	if (isdigit(*symbol) || (*symbol == '-' && isdigit(token[1]))) {
//		*value = atoi(token);
//		return operand;
//	}
//
//	switch (*symbol)
//	{
//	case '(': return lparen;
//	case ')': return rparen;
//	case '+': return plus;
//	case '-': return minus;
//	case '/': return divide;
//	case '*': return times;
//	case '%': return mod;
//	case '\0': return eos;
//	default:
//		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
//	}
//}
//void postfix(void)
//{
//	char symbol;
//	precedence token;
//	int value;
//
//	expr_ptr = expr; // 전역 expr 사용
//	context = NULL;
//
//	top = 0; // eos를 스택에 삽입한다.
//	stack[0] = eos;
//	while ((token = getToken(&symbol, &value)) != eos)
//	{	// 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴.
//		if (token == operand)
//			printf("%d ", value);
//		else if (token == rparen)
//		{
//			while (stack[top] != lparen)
//			{
//				printToken(pop());
//				printf(" ");
//			}
//			pop(); // 완쪽 괄호를 버린다.
//		}
//		else
//		{	// symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴.
//			while (isp[stack[top]] >= icp[token])
//			{
//				printToken(pop());
//				printf(" ");
//			}
//			push(token);
//		}
//	}
//	while ((token = pop()) != eos)
//	{
//		printToken(token);
//		printf(" ");
//	}
//	printf("\n");
//}
//int eval(void)
//{
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int value;
//
//	eval_top = -1;
//	token = getToken(&symbol, &value);
//	while (token != eos)
//	{
//		if (token == operand)
//			eval_push(value);
//		else
//		{
//			/* 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함. */
//			op2 = eval_pop();
//			op1 = eval_pop();
//			switch (token)
//			{
//			case plus: eval_push(op1 + op2);
//				break;
//			case minus: eval_push(op1 - op2);
//				break;
//			case times: eval_push(op1 * op2);
//				break;
//			case divide: eval_push(op1 / op2);
//				break;
//			case mod: eval_push(op1 % op2);
//			}
//		}
//		token = getToken(&symbol, &value);
//	}
//	return eval_pop(); // 결과를 반환.
//}
//int main()
//{
//	printf("중위 표기식을 입력하세요.(공백으로 구분.) : ");
//	fgets(expr, MAX_EXPR_SIZE, stdin); // 공백 포함 입력 받기
//	printf("후위 표기식: ");
//	postfix();
//	printf("\n후위 표기식을 입력하세요 (공백으로 구분): ");
//	fgets(expr, MAX_EXPR_SIZE, stdin);
//	printf("후위 표기식 연산 결과: %d\n", eval());
//}

/* 3. 1을 전위식표기로 구현 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//#define MAX_EXPR_SIZE 100
//
//typedef enum {
//	lparen, rparen, plus, minus, times, divide, mod, eos, operand
//} precedence;
///* isp와 icp 배열 -- 인덱스는 연산자
//lparen, rparen, plus, minus, times, divide, mod, eos, operand의 우선순위 값 */
//int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
//int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
//char expr[MAX_EXPR_SIZE];
//
//precedence stack[MAX_STACK_SIZE];
//int top = -1;
//// boolean isempty (stack) ::= top < 0;
//// boolean isfull (stack) ::= top >= max_stack_size - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//}
//precedence stackEmpty()
//{
//	//precedence dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치. (버퍼없이 바로 출력 가능.)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료.
//	//return dummy;
//}
//void push(precedence item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	stack[++top] = item;
//}
//precedence pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return stack[top--];
//}
//
//int eval_stack[MAX_STACK_SIZE];
//int eval_top = -1;
//void eval_push(int item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인.
//		stackFull();
//	eval_stack[++top] = item;
//}
//int eval_pop()
//{ // stack의 최상의 원소를 반환.
//	if (top == -1) // 스택이 있는지 확인.
//		return stackEmpty(); // 오류 Key를 반환.
//	return eval_stack[top--];
//}
//
//char getSymbol(precedence token)
//{
//	switch (token)
//	{
//	case plus: return '+';
//	case minus: return '-';
//	case times: return '*';
//	case divide: return '/';
//	case mod: return '%';
//	case lparen: return '(';
//	case rparen: return ')';
//	default: return '?'; // 오류 방지로 임시
//	}
//}
//precedence getToken(char* symbol, int* n)
//{	/* 프로그램 3.14: 입력 스트링으로부터 토큰을 가져오는 함수.
//	다음 토큰을 취한다.
//	symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 함수 이름으로 반환된다. */
//	*symbol = expr[(*n)++];
//	switch (*symbol)
//	{
//	case '(': return lparen;
//	case ')': return rparen;
//	case '+': return plus;
//	case '-': return minus;
//	case '/': return divide;
//	case '*': return times;
//	case '%': return mod;
//	case '\0': return eos;
//	default:
//		return operand; // 에러 검사는 하지 않고 기본 값은 피연산자.
//	}
//}
//
//void reverse(char* str)
//{	// 수식을 뒤집는 함수.
//	int i, len = strlen(str);
//	for (i = 0; i < len / 2; i++) {
//		char tmp = str[i];
//		str[i] = str[len - i - 1];
//		str[len - i - 1] = tmp;
//	}
//}
//
//void swapParentheses(char* str)
//{
//	for (int i = 0; str[i] != '\0'; i++) {
//		if (str[i] == '(') str[i] = ')';
//		else if (str[i] == ')') str[i] = '(';
//	}
//}
//
//void prefix()
//{	// 전위 표기식: 중위 수식을 뒤집어, 후위 수식 변환 후, 다시 뒤집으면 전위 수식.
//	char original[MAX_EXPR_SIZE];
//	strcpy_s(original, expr);
//
//	reverse(original); // 수식 뒤집기.
//
//	swapParentheses(original); // 괄호 반전.
//
//	// expr에 변환된 수식 넣고 후위로 변환
//	strcpy_s(expr, original);
//	printf("변환된 (뒤집힌 + 괄호교체된) 중위 수식: %s\n", expr);
//	printf("전위 표기식: ");
//
//	// 후위 표기식을 만들고, 출력 순서를 반대로 하면 전위 표기식.
//	char symbol;
//	precedence token;
//	int n = 0;
//	top = 0;
//	stack[0] = eos;
//	char result[MAX_EXPR_SIZE];
//	int res_index = 0;
//
//	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {
//		if (token == operand) {
//			result[res_index++] = symbol;
//		}
//		else if (token == rparen) {
//			while (stack[top] != lparen)
//				result[res_index++] = getSymbol(pop());
//			pop(); // 왼쪽 괄호 제거
//		}
//		else {
//			while (isp[stack[top]] >= icp[token])
//				result[res_index++] = getSymbol(pop());
//			push(token);
//		}
//	}
//	while ((token = pop()) != eos)
//		result[res_index++] = getSymbol(token);
//
//	result[res_index] = '\0';
//
//	reverse(result); // 후위 표기식을 전위 표기식으로.
//
//	for (int i = 0; i < res_index; i++)
//	{
//		printf("%c", result[i]);
//	}
//}
//
//int eval(void)
//{
//	precedence token;
//	char symbol;
//	int op1, op2;
//	int n = strlen(expr) - 1;  // 오른쪽부터 시작.
//	top = -1;  // eval_stack 초기화.
//
//	while (n >= 0)
//	{
//		symbol = expr[n--];
//
//		switch (symbol)
//		{
//		case '+': token = plus; break;
//		case '-': token = minus; break;
//		case '*': token = times; break;
//		case '/': token = divide; break;
//		case '%': token = mod; break;
//		default: token = operand;
//		}
//
//		if (token == operand)
//			eval_push(symbol - '0');  // char 타입 숫자 int 변환.
//		else
//		{
//			op1 = eval_pop();  // 왼쪽.
//			op2 = eval_pop();  // 오른쪽.
//
//			switch (token)
//			{
//			case plus: eval_push(op1 + op2); break;
//			case minus: eval_push(op1 - op2); break;
//			case times: eval_push(op1 * op2); break;
//			case divide: eval_push(op1 / op2); break;
//			case mod: eval_push(op1 % op2); break;
//			}
//		}
//	}
//	return eval_pop();  // 최종 결과.
//}
//int main()
//{
//	printf("중위 표기식을 입력하세요. : ");
//	scanf_s("%s", expr, (unsigned)_countof(expr));
//
//	printf("\n전위 표기식: ");
//	prefix();
//
//	printf("\n전위 표기식을 입력하세요. : ");
//	scanf_s("%s", expr, (unsigned)_countof(expr));
//	printf("전위 표기식 연산 결과: %d\n", eval());
//}

/* 3. 2를 전위식표기로 구현 */



/* 4. 미로 찾기(교재 그림 3.8~3.10, 프로그램 3.12) */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 1000
//#define MAX_ROW 12
//#define MAX_COL 15
//#define EXIT_ROW 11
//#define EXIT_COL 14
//#define TRUE 1
//#define FALSE 0
//typedef struct {
//	short int vert; // 행
//	short int horiz; // 열
//} offsets;
//offsets move[8] = {	 // 각 방향에 대한 이동 배열
//	{-1, 0},	// 북 (N)
//	{-1, 1},	// 북동 (NE)
//	{0, 1},		// 동 (E)
//	{1, 1},		// 남동 (SE)
//	{1, 0},		// 남 (S)
//	{1, -1},	// 남서 (SW)
//	{0, -1},	// 서 (W)
//	{-1, -1}	// 북서 (NW)
//};
//typedef struct {
//	short int row; // 행
//	short int col; // 열
//	short int dir;
//} element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//// Boolean IsEmpty (Stack) ::= top < 0;
//// Boolean IsFull (Stack) ::= top >= MAX_STACK_SIZE - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//void push(element item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인
//		stackFull();
//	stack[++top] = item;
//}
//element pop()
//{ // stack의 최상의 원소를 반환
//	if (top == -1) // 스택이 있는지 확인
//		return stackEmpty(); // 오류 Key를 반환
//	return stack[top--];
//}
//int mark[MAX_ROW][MAX_COL] = { 0 };
//int maze[MAX_ROW][MAX_COL] = {
//	{ 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
//	{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
//	{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
//	{ 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
//	{ 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
//	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
//	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
//	{ 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 }
//};
//void path(void)
//{	// 미로를 통과하는 경로가 있으면 그 경로를 출력한다.
//	int i, row, col, nextRow, nextCol, dir, found = FALSE;
//	element position;
//	mark[1][1] = 1; top = 0;
//	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
//	while (top > -1 && !found)
//	{
//		position = pop();
//		row = position.row; col = position.col;
//		dir = position.dir;
//		while (dir < 8 && !found)
//		{	// dir 방향으로 이동
//			nextRow = row + move[dir].vert;
//			nextCol = col + move[dir].horiz;
//			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
//				found = TRUE;
//			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
//			{
//				mark[nextRow][nextCol] = 1;
//				position.row = row; position.col = col;
//				position.dir = ++dir;
//				push(position);
//				row = nextRow; col = nextCol; dir = 0;
//			}
//			else ++dir;
//		}
//	}
//	if (found)
//	{
//		printf("The path is:\n");
//		printf("row	col\n");
//		for (i = 0; i <= top; i++)
//			printf("%2d%5d\n", stack[i].row, stack[i].col);
//		printf("%2d%5d\n", row, col);
//		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
//	}
//	else
//		printf("The maze does not have a path\n");
//}
//int main()
//{
//	path();
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 1000
//#define MAX_ROW 12
//#define MAX_COL 15
//#define EXIT_ROW 11
//#define EXIT_COL 14
//#define TRUE 1
//#define FALSE 0
//typedef struct {
//	short int vert; // 행
//	short int horiz; // 열
//} offsets;
//offsets move[8] = {	 // 각 방향에 대한 이동 배열
//	{-1, 0},	// 북 (N)
//	{-1, 1},	// 북동 (NE)
//	{0, 1},		// 동 (E)
//	{1, 1},		// 남동 (SE)
//	{1, 0},		// 남 (S)
//	{1, -1},	// 남서 (SW)
//	{0, -1},	// 서 (W)
//	{-1, -1}	// 북서 (NW)
//};
//typedef struct {
//	short int row; // 행
//	short int col; // 열
//	short int dir;
//} element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//// Boolean IsEmpty (Stack) ::= top < 0;
//// Boolean IsFull (Stack) ::= top >= MAX_STACK_SIZE - 1;
//void stackFull()
//{
//	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//void push(element item)
//{ // 전역 stack에 item을 삽입
//	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인
//		stackFull();
//	stack[++top] = item;
//}
//element pop()
//{ // stack의 최상의 원소를 반환
//	if (top == -1) // 스택이 있는지 확인
//		return stackEmpty(); // 오류 Key를 반환
//	return stack[top--];
//}
//int mark[MAX_ROW][MAX_COL] = { 0 };
//int maze[MAX_ROW][MAX_COL] = {
//	{ 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
//	{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
//	{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
//	{ 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
//	{ 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
//	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
//	{ 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
//	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
//	{ 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 }
//};
//void path(void)
//{	// 미로를 통과하는 경로가 있으면 그 경로를 출력한다.
//	int i, row, col, nextRow, nextCol, dir, found = FALSE;
//	element position;
//	mark[1][1] = 1; top = 0;
//	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
//	while (top > -1 && !found)
//	{
//		position = pop();
//		row = position.row; col = position.col;
//		dir = position.dir;
//		while (dir < 8 && !found)
//		{	// dir 방향으로 이동
//			nextRow = row + move[dir].vert;
//			nextCol = col + move[dir].horiz;
//			if (nextRow >= 0 && nextRow < MAX_ROW && nextCol >= 0 && nextCol < MAX_COL)
//			{	// nextRow와 nextCol이 배열(미로) 범위를 벗어나지 않도록 방지.
//				if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
//				{
//					position.row = row;
//					position.col = col;
//					position.dir = dir;
//					push(position); // 도착 전 위치 저장
//
//					position.row = nextRow;
//					position.col = nextCol;
//					position.dir = 0;
//					push(position); // 도착 위치 저장
//					found = TRUE;
//				}
//				else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
//				{
//					mark[nextRow][nextCol] = 1;
//					position.row = row; position.col = col;
//					position.dir = ++dir;
//					push(position);
//					row = nextRow; col = nextCol; dir = 0;
//				}
//				else ++dir;
//			}
//			else ++dir;
//		}
//	}
//	if (found)
//	{
//		printf("The path is:\n");
//		printf("row col\n");
//		for (i = 0; i <= top; i++)
//			printf("%2d%5d\n", stack[i].row, stack[i].col);
//		printf("EXIT (row / col): %2d%5d\n", EXIT_ROW, EXIT_COL);
//	}
//	else
//		printf("The maze does not have a path\n");
//}
//int main()
//{
//	path();
//}
