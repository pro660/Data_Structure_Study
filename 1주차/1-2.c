// 2.1 1개의 스택을 만들어 push,pop 하기
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 10
typedef struct {
	char key;
}element;
typedef struct stack* stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
}stack;
stackPointer top[MAX_STACKS];
element stackEmpty()
{
	fprintf(stderr, "스택이 없습니다.\n");
	exit(1);
}
void push(int i, element item)
{
	stackPointer temp;
	temp = (stackPointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}
element pop(int i)
{
	stackPointer temp = top[i];
	element item;
	if (!temp)
		return stackEmpty();
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}
void printStack(int i) 
{
	stackPointer current = top[i];
	while (current) 
	{
		printf("[%c] → ", current->data.key);
		current = current->link;
	}
	printf("NULL\n");
}
int main()
{
	element item;
	char n[MAX_STACKS];
	int i;
	for (i = 0; i < MAX_STACKS; i++)
		top[i] = NULL;
	for (i = 0; i < 3; i++) 
	{
		printf("문자를 입력하시오 (-1 입력시 종료): ");
		scanf_s("%s", n, MAX_STACKS);
		if (strcmp(n, "-1") == 0) 
		{
			printf("프로그램을 종료합니다.\n");
			exit(EXIT_FAILURE);
		}
		item.key = n[0];
		push(0, item);
		printStack(0);
	}
	printf("\n스택 pop 결과:\n");
	for (i = 0; i < 3; i++) {
		item = pop(0);
		printf("pop: %c\n", item.key);
		printStack(0);
	}
}

// 2.2 연결리스트로 1개의 큐를 만들어 삽입 삭제 하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10
typedef struct {
	char key;
}element;
typedef struct queue* queuePointer;
typedef struct queue {
	element data;
	queuePointer link;
};
queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
element queueEmpty()
{
	fprintf(stderr, "큐가 없습니다. \n");
	exit(1);
}
void addq(int i, element item)
{
	queuePointer temp;
	temp = (queuePointer)malloc(sizeof(struct queue));
	temp->data = item;
	temp->link = NULL;
	if (front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	rear[i] = temp;
}
element deleteq(int i)
{
	queuePointer temp = front[i];
	element item;
	if (!temp)
		return queueEmpty();
	item = temp->data;
	front[i] = temp->link;
	if (!front[i]) 
		rear[i] = NULL;
	free(temp);
	return item;
}
void printQueue(int i) {
	queuePointer temp = front[i];
	while (temp) {
		printf("[%c] → ", temp->data.key);
		temp = temp->link;
	}
	printf("NULL\n");
}
int main(void)
{
	element e;
	char n[MAX_QUEUE];
	for (int i = 0; i < MAX_QUEUE; i++)
		front[i] = rear[i] = NULL;
	for (int i = 0; i < 3; i++) 
	{
		printf("문자를 입력하시오 (-1 입력시 종료): ");
		scanf_s("%s", n,MAX_QUEUE);
		if (strcmp(n, "-1") == 0) {
			printf("프로그램을 종료합니다.\n");
			exit(EXIT_FAILURE);
		}
		e.key = n[0];
		addq(0, e);
		printQueue(0); 
	}
	printf("\n큐에서 삭제된 데이터:\n");
	for (int i = 0; i < 3; i++) {
		e = deleteq(0);
		printf("delete: %c\n", e.key);
		printQueue(0); 
	}
}