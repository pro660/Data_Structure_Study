// 최대 10개의 값을 저장하는 스택 만들기
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_STACK_SIZE 10
//typedef struct
//{
//	char key;
//}element;
//element stack[MAX_STACK_SIZE];
//int top = -1;
//void stackFull()
//{
//	fprintf(stderr, "스택이 가득 찼습니다.\n");
//	exit(EXIT_FAILURE);
//}
//element stackEmpty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "스택이 비어있습니다.\n");
//	exit(EXIT_FAILURE);
//	return dummy;
//}
//void push(element item)
//{
//	if (top >= MAX_STACK_SIZE - 1)
//		stackFull();
//	stack[++top] = item;
//}
//element pop()
//{
//	if (top == -1)
//		return stackEmpty();
//	return stack[top--];
//}
//int main(void)
//{
//	element n;
//	int i;
//	for (i = 0; i < MAX_STACK_SIZE; i++)
//	{
//		printf("입력 : ");
//		scanf_s(" %c", &n.key, 1);
//		push(n);
//	}
//	for (i = 0; i < MAX_STACK_SIZE; i++)
//	{
//		element temp = pop();
//		printf("%c\n", temp.key);
//	}
//}


// 원형 큐를 만들어 add, delete 하기
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE_SIZE 10
//typedef struct {
//	char key;
//}element;
//element queue[MAX_QUEUE_SIZE];
//int rear = 0;
//int front = 0;
//void queuefull()
//{
//	fprintf(stderr, "Queue is full\n");
//	exit(1);
//}
//element queueempty()
//{
//	element dummy = { '\0' };
//	fprintf(stderr, "Queue is empty\n");
//	exit(1);
//	return dummy;
//}
//void addq(element item)
//{
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	if (front == rear)
//		queuefull();
//	queue[rear] = item;
//}
//element deleteq()
//{
//	element item;
//	if (front == rear)
//		return queueempty();
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return queue[front];
//}
//int main(void)
//{
//	element n;
//	int i;
//	for (i = 0; i < MAX_QUEUE_SIZE-1; i++)
//	{
//		printf("입력 : ");
//		scanf_s(" %c", &n.key, 1);
//		addq(n);
//	}
//	for (i = 0; i < MAX_QUEUE_SIZE-1; i++)
//	{
//		element temp = deleteq();
//		printf("%c\n", temp.key);
//	}
//}

// 1개의 스택을 만들어 push,pop 하기
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_STACKS 10
//typedef struct {
//	char key;
//}element;
//typedef struct stack* stackPointer;
//typedef struct stack {
//	element data;
//	stackPointer link;
//}stack;
//stackPointer top[MAX_STACKS];
//element stackEmpty()
//{
//	fprintf(stderr, "스택이 없습니다.\n");
//	exit(1);
//}
//void push(int i, element item)
//{
//	stackPointer temp;
//	temp = (stackPointer)malloc(sizeof(*temp));
//	temp->data = item;
//	temp->link = top[i];
//	top[i] = temp;
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
//void printStack(int i) 
//{
//	stackPointer current = top[i];
//	while (current) 
//	{
//		printf("[%c] → ", current->data.key);
//		current = current->link;
//	}
//	printf("NULL\n");
//}
//int main()
//{
//	element item;
//	char n[MAX_STACKS];
//	int i;
//	for (i = 0; i < MAX_STACKS; i++)
//		top[i] = NULL;
//	for (i = 0; i < 3; i++) 
//	{
//		printf("문자를 입력하시오 (-1 입력시 종료): ");
//		scanf_s("%s", n, MAX_STACKS);
//		if (strcmp(n, "-1") == 0) 
//		{
//			printf("프로그램을 종료합니다.\n");
//			exit(EXIT_FAILURE);
//		}
//		item.key = n[0];
//		push(0, item);
//		printStack(0);
//	}
//	printf("\n스택 pop 결과:\n");
//	for (i = 0; i < 3; i++) {
//		item = pop(0);
//		printf("pop: %c\n", item.key);
//		printStack(0);
//	}
//}

// 연결리스트로 1개의 큐를 만들어 삽입 삭제 하는 프로그램
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_QUEUE 10
//typedef struct {
//	char key;
//}element;
//typedef struct queue* queuePointer;
//typedef struct queue {
//	element data;
//	queuePointer link;
//};
//queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
//element queueEmpty()
//{
//	fprintf(stderr, "큐가 없습니다. \n");
//	exit(1);
//}
//void addq(int i, element item)
//{
//	queuePointer temp;
//	temp = (queuePointer)malloc(sizeof(struct queue));
//	temp->data = item;
//	temp->link = NULL;
//	if (front[i])
//		rear[i]->link = temp;
//	else
//		front[i] = temp;
//	rear[i] = temp;
//}
//element deleteq(int i)
//{
//	queuePointer temp = front[i];
//	element item;
//	if (!temp)
//		return queueEmpty();
//	item = temp->data;
//	front[i] = temp->link;
//	if (!front[i]) 
//		rear[i] = NULL;
//	free(temp);
//	return item;
//}
//void printQueue(int i) {
//	queuePointer temp = front[i];
//	while (temp) {
//		printf("[%c] → ", temp->data.key);
//		temp = temp->link;
//	}
//	printf("NULL\n");
//}
//int main(void)
//{
//	element e;
//	char n[MAX_QUEUE];
//	for (int i = 0; i < MAX_QUEUE; i++)
//		front[i] = rear[i] = NULL;
//	for (int i = 0; i < 3; i++) 
//	{
//		printf("문자를 입력하시오 (-1 입력시 종료): ");
//		scanf_s("%s", n,MAX_QUEUE);
//		if (strcmp(n, "-1") == 0) {
//			printf("프로그램을 종료합니다.\n");
//			exit(EXIT_FAILURE);
//		}
//		e.key = n[0];
//		addq(0, e);
//		printQueue(0); 
//	}
//	printf("\n큐에서 삭제된 데이터:\n");
//	for (int i = 0; i < 3; i++) {
//		e = deleteq(0);
//		printf("delete: %c\n", e.key);
//		printQueue(0); 
//	}
//}


// 배열을 이용하여 다항식 계산
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) ((x)<(y)? -1:((x)==(y))?0:1)
#define MAX_TERMS 100
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "다항식에 항이 너무 많다.");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}
void padd(int startA, int finishA, int startB, int finishB,
	int* startD, int* finishD)
{
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].expon, terms[startB].expon))
		{
		case -1: attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;
}
int main(void)
{
	float a;
	int b, i;
	int starta, startb, startc, finisha, finishb, startd, finishd;
	starta = avail;
	while (1)
	{
		printf("다항식 A의 계수를 입력하시오. : ");
		scanf_s("%f", &a);
		if (a == 0)
			break;
		printf("다항식 A의 지수를 입력하시오. : ");
		scanf_s("%d", &b);
		attach(a, b);
	}
	finisha = avail - 1;
	startb = avail;
	while (1)
	{
		printf("다항식 B의 계수를 입력하시오. : ");
		scanf_s("%f", &a);
		if (a == 0)
			break;
		printf("다항식 B의 지수를 입력하시오. : ");
		scanf_s("%d", &b);
		attach(a, b);
	}
	finishb = avail - 1;
	padd(starta, finisha, startb, finishb, &startd, &finishd);
	printf("다항식 A : ");
	for (i = starta; i <= finisha; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finisha)
			printf(" + ");
	}
	printf("\n다항식 B : ");
	for (i = startb; i < finishb; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finishb)
			printf(" + ");
	}
	printf("\n다항식 D : ");
	for (i = startd; i <= finishd; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finishd)
			printf(" + ");
	}
}

// 연결리스트를 이용하여 다항식 덧셈하기
//#include <stdio.h>
//#include <stdlib.h>
//#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)
//typedef struct polyNode* polyPointer;
//typedef struct polyNode {
//	int coef;
//	int expon;
//	polyPointer link;
//};
//polyPointer a, b;
//void attach(float coefficient, int exponent, polyPointer* ptr)
//{
//	polyPointer temp;
//	temp = (polyPointer)malloc(sizeof(*temp));
//	temp->coef = coefficient;
//	temp->expon = exponent;
//	(*ptr)->link = temp;
//	*ptr = temp;
//}
//polyPointer padd(polyPointer a, polyPointer b)
//{
//	polyPointer c, rear, temp;
//	int sum;
//	rear = (polyPointer)malloc(sizeof(*rear));
//	c = rear;
//	while (a && b)
//	{
//		switch (COMPARE(a->expon, b->expon))
//		{
//		case -1:
//			attach(b->coef, b->expon, &rear);
//			b = b->link;
//			break;
//		case 0:
//			sum = a->coef + b->coef;
//			if (sum) attach(sum, a->expon, &rear);
//			a = a->link; b = b->link; break;
//		case 1:
//			attach(a->coef, a->expon, &rear);
//			a = a->link;
//		}
//	}
//	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
//	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
//	rear->link = NULL;
//	temp = c; c = c->link; free(temp);
//	return c;
//}
//void printPoly(polyPointer poly)
//{
//	while (poly)
//	{
//		printf("%dx^%d", poly->coef, poly->expon);
//		if (poly->link)
//			printf(" + ");
//		poly = poly->link;
//	}
//	printf("\n");
//}
//int main(void)
//{
//	polyPointer rear;
//	int j, k;
//	rear = (polyPointer)malloc(sizeof(struct polyNode));
//	a = rear;
//	printf("다항식 A 입력\n");
//	while (1)
//	{
//		printf("계수를 입력하시오. : ");
//		scanf_s("%d", &k);
//		if (k == 0) break;
//		printf("지수를 입력하시오. : ");
//		scanf_s("%d", &j);
//		attach(k, j, &rear);
//		if (j == 0) break;
//	}
//	rear->link = NULL;
//	polyPointer temp = a; a = a->link; free(temp);
//	rear = (polyPointer)malloc(sizeof(struct polyNode));
//	b = rear;
//	printf("다항식 B 입력\n");
//	while (1)
//	{
//		printf("계수를 입력하시오. : ");
//		scanf_s("%d", &k);
//		if (k == 0) break;
//		printf("지수를 입력하시오. : ");
//		scanf_s("%d", &j);
//		attach(k, j, &rear);
//		if (j == 0) break;
//	}
//	rear->link = NULL;
//	temp = b; b = b->link; free(temp);
//	printf("다항식 A : ");
//	printPoly(a);
//	printf("다항식 B : ");
//	printPoly(b);
//	polyPointer result = padd(a, b);
//	printf("다항식의 합 : ");
//	printPoly(result);
//}