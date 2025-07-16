/*
1. 문자를 저장하기 위해 배열을 이용한 스택과 원형 큐 구현
2. 문자를 저장하기 위해 연결리스트를 이용한 스택과 큐 구현
   (삽입, 삭제, 출력, 종료 기능)
3. 다항식의 덧셈(배열 버전, 리스트 버전) 복습
*/

/* 문자 저장 배열 스택 */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 10 // 최대 스택 크기
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
//int main()
//{
//	element item;
//	int n, i;
//
//	for (n = 0; n < MAX_STACK_SIZE; n++)
//	{
//		printf("%d. 입력: ", n + 1);
//		scanf_s(" %c", &i.key, 1);
//		push(i);
//	}
//	for (n = 0; n < MAX_STACK_SIZE; n++)
//	{
//		element temp = pop();
//		printf("%c\n", temp.key);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACK_SIZE 10 // 최대 스택 크기
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
//int main()
//{
//	element item;
//	int menu, count, i;
//
//	while (1)
//	{
//		printf("1. 삽입 2. 삭제 3. 종료 => ");
//		scanf_s("%d", &menu);
//		switch (menu)
//		{
//		case 1:
//			printf("몇 개를 삽입? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				printf("입력: ");
//				scanf_s(" %c", &item.key, sizeof(char));
//				push(item);
//			}
//			break;
//		case 2:
//			printf("몇 개를 삭제? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				element temp = pop();
//				printf("삭제: %c\n", temp.key);
//			}
//			break;
//		case 3:
//			return 0;
//		default:
//			break;
//		}
//	}
//}

/* 문자 저장 배열 원형 큐 */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 10 // 큐의 최대 크기
//// queue createq(maxqueuesize) : : =
//typedef struct {
//	char key;
//}  element;
//element queue[MAX_QUEUE_SIZE];
//int rear = 0;
//int front = 0;
//// boolean isemptyq(queue) : : = front == rear
//// boolean isfullq(queue) : : = rear == max_queue_size - 1
//void queuefull()
//{
//	rear = 0;
//	fprintf(stderr, "Queue is full\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//}
//element queueempty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//void addq(element item)
//{ // queue에 item을 삽입
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	if (front == rear)
//		queuefull(); // rear를 리셋시키고 오류를 프린트
//	queue[rear] = item;
//}
//element deleteq()
//{ // queued의 앞 원소를 삭제
//	element item;
//	if (front == rear)
//		return queueempty();  // 오류 key를 반환
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return queue[front];
//}
//void main()
//{
//	element i;
//	int n;
//
//	for (n = 0; n < MAX_QUEUE_SIZE - 1; n++)
//	{
//		printf("%d. 입력: ", n + 1);
//		scanf_s(" %c", &i.key, 1);
//		addq(i);
//	}
//	for (n = 0; n < MAX_QUEUE_SIZE - 1; n++)
//	{
//		element temp = deleteq();
//		printf("%c\n", temp.key);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 10 // 큐의 최대 크기
//// queue createq(maxqueuesize) : : =
//typedef struct {
//	char key;
//}  element;
//element queue[MAX_QUEUE_SIZE];
//int rear = 0;
//int front = 0;
//// boolean isemptyq(queue) : : = front == rear
//// boolean isfullq(queue) : : = rear == max_queue_size - 1
//void queuefull()
//{
//	rear = 0;
//	fprintf(stderr, "Queue is full\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//}
//element queueempty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//void addq(element item)
//{ // queue에 item을 삽입
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	if (front == rear)
//		queuefull(); // rear를 리셋시키고 오류를 프린트
//	queue[rear] = item;
//}
//element deleteq()
//{ // queued의 앞 원소를 삭제
//	element item;
//	if (front == rear)
//		return queueempty();  // 오류 key를 반환
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return queue[front];
//}
//int main()
//{
//	element item;
//	int menu, count, i;
//
//	while (1)
//	{
//		printf("1. 삽입 2. 삭제 3. 종료 => ");
//		scanf_s("%d", &menu);
//		switch (menu)
//		{
//		case 1:
//			printf("몇 개를 삽입? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				printf("입력: ");
//				scanf_s(" %c", &item.key, sizeof(char));
//				addq(item);
//			}
//			break;
//		case 2:
//			printf("몇 개를 삭제? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				element temp = deleteq();
//				printf("삭제: %c\n", temp.key);
//			}
//			break;
//		case 3:
//			return 0;
//		default:
//			break;
//		}
//	}
//}

/* 문자 저장 연결리스트 스택 */

//#include <stdio.h>
//#include <stdlib.h>
//#define MALLOC(p, s)\
// if (! ((p) = (stackPointer)malloc(s))) {\
//fprintf(stderr, "Insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct {
//	int key;
//} element;
//typedef struct stack* stackPointer;
//typedef struct stack {
//	element data;
//	stackPointer link;
//} stack;
//stackPointer top;
//void push(element item)
//{
//	stackPointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = item;
//	temp->link = top;
//	top = temp;
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//element pop()
//{
//	stackPointer temp = top;
//	element item;
//	if (!temp)
//		return stackEmpty();
//	item = temp->data;
//	top = temp->link;
//	free(temp);
//	return item;
//}
//void printStack(stackPointer first)
//{
//	printf("The Stack contains: ");
//	for (; first; first = first->link)
//		printf("%4d", first->data);
//	printf("\n");
//}
//void main()
//{
//	element item1 = { 1 };
//
//	push(item1);
//	printStack(top);
//	printf("%d\n", pop());
//	printStack(top);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACKS 10 // 스택의 최대 수
//#define MALLOC(p, s)\
// if (! ((p) = (stackPointer)malloc(s))) {\
//fprintf(stderr, "Insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct {
//	char key;
//} element;
//typedef struct stack* stackPointer;
//typedef struct stack {
//	element data;
//	stackPointer link;
//};
//stackPointer top[MAX_STACKS];
//void push(int i, element item)
//{
//	stackPointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = item;
//	temp->link = top[i];
//	top[i] = temp;
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//element pop(int i)
//{
//	stackPointer temp = top[i];
//	element item;
//	if (!temp)
//		return stackEmpty();
//	item = temp->data;
//	top[i] = temp->link;
//	free(temp);
//	return item;
//}
//void printStack(stackPointer first)
//{
//	printf("The Stack contains: ");
//	for (; first; first = first->link)
//		printf("%4c", first->data.key);
//	printf("\n");
//}
//int main()
//{
//	element item;
//	int menu, count, i;
//
//	while (1)
//	{
//		printf("1. 삽입 2. 삭제 3. 출력 4. 종료 => ");
//		scanf_s("%d", &menu);
//		switch (menu)
//		{
//		case 1:
//			printf("몇 개를 삽입? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				printf("입력: ");
//				scanf_s(" %c", &item.key, sizeof(char));
//				push(0, item);
//			}
//			break;
//		case 2:
//			printf("몇 개를 삭제? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				element temp = pop(0);
//				printf("삭제: %c\n", temp.key);
//			}
//			break;
//		case 3:
//			printStack(top[0]); // 다중 스택에서 index 0에 해당하는 스택만 사용
//			break;
//		case 4:
//			return 0;
//		default:
//			break;
//		}
//	}
//}

/* 동적 연결 큐 */

//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#define MALLOC(p, s)\
// if (! ((p) = (queuePointer)malloc(s))) {\
//fprintf(stderr, "Insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//#define MAX_QUEUE 10 // 큐의 최대 원소수
//typedef struct {
//	int key;
//} element;
//typedef struct queue* queuePointer;
//typedef struct queue {
//	element data;
//	queuePointer link;
//} stack;
//queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
//void addq(int i, element item)
//{ // 큐 i의 뒤에 원소를 삽입
//	queuePointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = item;
//	temp->link = NULL;
//	if (front[i])
//		rear[i]->link = temp;
//	else
//		front[i] = temp;
//	rear[i] = temp;
//}
//element queueEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//element deleteq(int i)
//{ /* 큐 i로부터 원소를 삭제 */
//	queuePointer temp = front[i];
//	element item;
//	if (!temp)
//		return queueEmpty();
//	item = temp->data;
//	front[i] = temp->link;
//	free(temp);
//	return item;
//}
//void printQueue(queuePointer first)
//{
//	printf("The Stack contains: ");
//	for (; first; first = first->link)
//		printf("%4d", first->data);
//	printf("\n");
//}
//void main()
//{
//	
//}

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE 10
//#define MALLOC(p, s)\
// if (! ((p) = (queuePointer)malloc(s))) {\
//fprintf(stderr, "insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct {
//	char key;
//} element;
//typedef struct queue* queuePointer;
//typedef struct queue {
//	element data;
//	queuePointer link;
//};
//queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
//void addq(int i, element item)
//{ // 큐 i의 뒤에 원소를 삽입
//	queuePointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->data = item;
//	temp->link = NULL;
//	if (front[i])
//		rear[i]->link = temp;
//	else
//		front[i] = temp;
//	rear[i] = temp;
//}
//element queueEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	return dummy;
//}
//element deleteq(int i)
//{ /* 큐 i로부터 원소를 삭제 */
//	queuePointer temp = front[i];
//	element item;
//	if (!temp)
//		return queueEmpty();
//	item = temp->data;
//	front[i] = temp->link;
//	free(temp);
//	return item;
//}
//void printQueue(queuePointer first)
//{
//	printf("the queue contains: ");
//	for (; first; first = first->link)
//		printf("%4c", first->data.key);
//	printf("\n");
//}
//int main()
//{
//	element item;
//	int menu, count, i, index = 0;
//
//	while (1)
//	{
//		printf("1. 삽입 2. 삭제 3. 출력 4. 종료 => ");
//		scanf_s("%d", &menu);
//		switch (menu)
//		{
//		case 1:
//			printf("몇 개를 삽입? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				printf("입력: ");
//				scanf_s(" %c", &item.key, sizeof(char));
//				addq(0, item);
//			}
//			break;
//		case 2:
//			printf("몇 개를 삭제? => ");
//			scanf_s("%d", &count);
//			for (i = 0; i < count; i++)
//			{
//				element temp = deleteq(0);
//				printf("삭제: %c\n", temp.key);
//			}
//			break;
//		case 3:
//			printQueue(front[0]); // 다중 큐에서 index 0에 해당하는 큐만 사용
//			break;
//		case 4:
//			return 0;
//		default:
//			break;
//		}
//	}
//}

/* (P.75) 프로그램 2.6: 두 다항식을 더하는 함수 */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 100 // 배열 terms의 최대 크기
//#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1) // x, y 를 비교하는 삼항연산자 매크로 함수
//typedef struct
//{
//	float coef; // 계수
//	int expon; // 지수
//} polynomial;
//polynomial terms[MAX_TERMS];
//int avail = 0;
//void attach(float coefficient, int exponent) // 계수와 지수를 전달.
//{ // 새로운 항을 다항식에 첨가한다.
//	if (avail >= MAX_TERMS)
//	{
//		fprintf(stderr, "다항식에 항이 너무 많다.\n");
//		exit(1);
//	}
//	terms[avail].coef = coefficient;
//	terms[avail++].expon = exponent; // avail 위치에 넣고 avail을 하나 증가 시킴
//}
//void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
//{
//	float coefficient;
//	*startD = avail;
//
//	while (startA <= finishA && startB <= finishB)
//	{
//		switch (COMPARE(terms[startA].expon, terms[startB].expon))
//		{
//		case -1: // A(x)의 expon이 B(x)의 expon보다 작은 경우
//			attach(terms[startB].coef, terms[startB].expon);
//			startB++;
//			break;
//		case 0: // A(x)와 B(X)의 expon이 같은 경우
//			coefficient = terms[startA].coef + terms[startB].coef;
//			if (coefficient) // coef가 0이 되는 경우 제외
//				attach(coefficient, terms[startA].expon);
//			startA++;
//			startB++;
//			break;
//		case 1: // A(x)의 expon이 B(x)의 expon보다 큰 경우
//			attach(terms[startA].coef, terms[startA].expon);
//			startA++;
//		}
//	}
//
//	for (; startA <= finishA; startA++) // A(x)의 나머지 항들을 첨가한다.
//		attach(terms[startA].coef, terms[startA].expon);
//	for (; startB <= finishB; startB++)
//		attach(terms[startB].coef, terms[startB].expon);
//	*finishD = avail - 1; // avail의 마지막 index를 저장
//}
//void main()
//{
//	float coefficient;
//	int exponent;
//	int startA, finishA, startB, finishB, n;
//	int startD, finishD;
//	printf("다항식 덧셈 프로그램\n");
//	printf("최고차항부터 순서대로 계수와 지수를 입력하시고, 계수에 0을 입력하면 해당 다항식의 입력은 종료됩니다.\n");
//
//	printf("\n다항식 A(x)\n\n");
//	startA = avail;
//	while (1) // 다항식 A(x) 입력
//	{
//		printf("다항식 A(x)의 계수를 입력하세요. : ");
//		scanf_s("%f", &coefficient);
//		if (coefficient == 0)
//			break;
//		printf("다항식 A(x)의 지수를 입력하세요. : ");
//		scanf_s("%d", &exponent);
//		attach(coefficient, exponent);
//		printf("\n");
//	}
//	finishA = avail - 1;
//	printf("\n다항식 B(x)\n\n");
//	startB = avail;
//	while (1) // 다항식 B(x) 입력
//	{
//		printf("다항식 B(x)의 계수를 입력하세요. : ");
//		scanf_s("%f", &coefficient);
//		if (coefficient == 0)
//			break;
//		printf("다항식 B(x)의 지수를 입력하세요. : ");
//		scanf_s("%d", &exponent);
//		attach(coefficient, exponent);
//		printf("\n");
//	}
//	finishB = avail - 1;
//	startD = avail;
//	finishD = avail;
//
//	printf("\nA(x) = "); // 다항식 A(x) 출력
//	for (n = startA; n <= finishA; n++)
//	{
//		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//		if (n != finishA)
//			printf("+ ");
//	}
//	printf("\nB(x) = "); // 다항식 B(x) 출력
//	for (n = startB; n <= finishB; n++)
//	{
//		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//		if (n != finishB)
//			printf("+ ");
//	}
//	padd(startA, finishA, startB, finishB, &startD, &finishD);
//	printf("\nD(x) = A(x) + B(x) = ");
//	for (n = startD; n <= finishD; n++)
//	{
//		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//		if (n != finishD)
//			printf("+ ");
//	}
//	printf("\n");
//}

/* 동적 연결 리스트 다항식의 덧셈 */

//#include <stdio.h>
//#include <stdlib.h>
//#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1) // x, y 를 비교하는 삼항연산자 매크로 함수
//#define MALLOC(p, s)\
// if (! ((p) = (polyPointer)malloc(s))) {\
//fprintf(stderr, "insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct polyNode* polyPointer;
//typedef struct polyNode {
//	int coef;
//	int expon;
//	polyPointer link;
//} polyNode;
//polyPointer a, b;
//void attach(int coefficient, int exponent, polyPointer* ptr)
//{ // coef = coefficient이고 expon = exponent인 새로운 노드를 생성하고, 그것을 ptr에 의해 참조되는 노드에 첨가한다. ptr을 갱신하여 이 새로운 노드를 참조하도록 한다.
//	polyPointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->coef = coefficient;
//	temp->expon = exponent;
//	(*ptr)->link = temp;
//	*ptr = temp;
//}
//polyPointer padd(polyPointer a, polyPointer b)
//{ // a와 b가 합산된 다항식을 반환
//	polyPointer c, rear, temp;
//	int sum;
//	MALLOC(rear, sizeof(*rear));
//	c = rear;
//	while (a && b)
//		switch (COMPARE(a->expon, b->expon))
//		{
//		case -1: // a->expon < b->expon
//			attach(b->coef, b->expon, &rear);
//			b = b->link;
//			break;
//		case 0: // a->expon = b->expon
//			sum = a->coef + b->coef;
//			if (sum) attach(sum, a->expon, &rear);
//			a = a->link;
//			b = b->link;
//			break;
//		case 1: // a->expon > b->expon
//			attach(a->coef, a->expon, &rear);
//			a = a->link;
//		}
//	// 리스트 a와 리스트 b의 나머지를 복사
//	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
//	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
//	rear->link = NULL;
//	// 필요 없는 초기 노드를 삭제
//	temp = c;
//	c = c->link;
//	free(temp);
//	return c;
//}
//void printPoly(polyPointer first)
//{
//	for (; first; first = first->link)
//	{
//		if (first->link) // NULL 값이 나오면 다음 항이 없음
//		{
//			if (first->coef < 0) // 계수가 0보다 작을 때
//				printf("(%dx^%d) + ", first->coef, first->expon);
//			else
//				printf("%dx^%d + ", first->coef, first->expon);
//		}
//		else
//		{
//			if (first->coef < 0) // 계수가 0보다 작을 때
//				printf("(%dx^%d)", first->coef, first->expon);
//			else
//				printf("%dx^%d", first->coef, first->expon);
//		}
//	}
//	printf("\n");
//}
//int main()
//{
//	polyPointer rearA, rearB, temp, c;
//
//	// 다항식 a 생성: 3x^14 + 2x^8 + 1
//	MALLOC(a, sizeof(*a));
//	rearA = a;
//	attach(3, 14, &rearA);
//	attach(2, 8, &rearA);
//	attach(1, 0, &rearA);
//	rearA->link = NULL;
//	temp = a; a = a->link; free(temp); // 헤더 제거
//
//	// 다항식 b 생성: 8x^14 -3x^10 + 10x^6
//	MALLOC(b, sizeof(*b));
//	rearB = b;
//	attach(8, 14, &rearB);
//	attach(-3, 10, &rearB);
//	attach(10, 6, &rearB);
//	rearB->link = NULL;
//	temp = b; b = b->link; free(temp); // 헤더 제거
//
//	// 출력: a, b
//	printf("Polynomial A(x) = ");
//	printPoly(a);
//	printf("Polynomial B(x) = ");
//	printPoly(b);
//
//	// 덧셈 결과
//	c = padd(a, b);
//	printf("Polynomial A(x) + B(x) = ");
//	printPoly(c);
//}
