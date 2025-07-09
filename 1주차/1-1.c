// 1.1 최대 10개의 값을 저장하는 스택 만들기
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 10
typedef struct
{
	char key;
}element;
element stack[MAX_STACK_SIZE];
int top = -1;
void stackFull()
{
	fprintf(stderr, "스택이 가득 찼습니다.\n");
	exit(EXIT_FAILURE);
}
element stackEmpty()
{
	element dummy = { '\0' };
	fprintf(stderr, "스택이 비어있습니다.\n");
	exit(EXIT_FAILURE);
	return dummy;
}
void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}
element pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}
int main(void)
{
	element n;
	int i;
	for (i = 0; i < MAX_STACK_SIZE; i++)
	{
		printf("입력 : ");
		scanf_s(" %c", &n.key, 1);
		push(n);
	}
	for (i = 0; i < MAX_STACK_SIZE; i++)
	{
		element temp = pop();
		printf("%c\n", temp.key);
	}
}

// 1.2 원형 큐를 만들어 add, delete 하기
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct {
	char key;
}element;
element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;
void queuefull()
{
	fprintf(stderr, "Queue is full\n");
	exit(1);
}
element queueempty()
{
	element dummy = { '\0' };
	fprintf(stderr, "Queue is empty\n");
	exit(1);
	return dummy;
}
void addq(element item)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queuefull();
	queue[rear] = item;
}
element deleteq()
{
	element item;
	if (front == rear)
		return queueempty();
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}
int main(void)
{
	element n;
	int i;
	for (i = 0; i < MAX_QUEUE_SIZE-1; i++)
	{
		printf("입력 : ");
		scanf_s(" %c", &n.key, 1);
		addq(n);
	}
	for (i = 0; i < MAX_QUEUE_SIZE-1; i++)
	{
		element temp = deleteq();
		printf("%c\n", temp.key);
	}
}