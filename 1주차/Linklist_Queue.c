/* 문자 저장 연결리스트를 이용한 큐 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10
#define MALLOC(p, s)\
 if (! ((p) = (queuePointer)malloc(s))) {\
fprintf(stderr, "insufficient memory");\
exit(EXIT_FAILURE);\
}
typedef struct {
	char key;
} element;
typedef struct queue* queuePointer;
typedef struct queue {
	element data;
	queuePointer link;
};
queuePointer front[MAX_QUEUE], rear[MAX_QUEUE];
void addq(int i, element item)
{ // 큐 i의 뒤에 원소를 삽입
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if (front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	rear[i] = temp;
}
element queueEmpty()
{
	element dummy = { '\0' };
	fprintf(stderr, "queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
	return dummy;
}
element deleteq(int i)
{ /* 큐 i로부터 원소를 삭제 */
	queuePointer temp = front[i];
	element item;
	if (!temp)
		return queueEmpty();
	item = temp->data;
	front[i] = temp->link;
	free(temp);
	return item;
}
void printQueue(queuePointer first)
{
	printf("the queue contains: ");
	for (; first; first = first->link)
		printf("%4c", first->data.key);
	printf("\n");
}
int main()
{
	element item;
	int menu, count, i, index = 0;

	while (1)
	{
		printf("1. 삽입 2. 삭제 3. 출력 4. 종료 => ");
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("몇 개를 삽입? => ");
			scanf_s("%d", &count);
			for (i = 0; i < count; i++)
			{
				printf("입력: ");
				scanf_s(" %c", &item.key, sizeof(char));
				addq(0, item);
			}
			break;
		case 2:
			printf("몇 개를 삭제? => ");
			scanf_s("%d", &count);
			for (i = 0; i < count; i++)
			{
				element temp = deleteq(0);
				printf("삭제: %c\n", temp.key);
			}
			break;
		case 3:
			printQueue(front[0]); // 다중 큐에서 index 0에 해당하는 큐만 사용
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
}
