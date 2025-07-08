/* 문자 저장 배열을 이용한 원형 큐 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 // 큐의 최대 크기
// queue createq(maxqueuesize) : : =
typedef struct {
	char key;
}  element;
element queue[MAX_QUEUE_SIZE];
int rear = 0;
int front = 0;
// boolean isemptyq(queue) : : = front == rear
// boolean isfullq(queue) : : = rear == max_queue_size - 1
void queuefull()
{
	rear = 0;
	fprintf(stderr, "Queue is full\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
}
element queueempty()
{
	element dummy = { '\0' };
	fprintf(stderr, "Queue is empty\n"); // standard error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(1); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
	return dummy;
}
void addq(element item)
{ // queue에 item을 삽입
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queuefull(); // rear를 리셋시키고 오류를 프린트
	queue[rear] = item;
}
element deleteq()
{ // queued의 앞 원소를 삭제
	element item;
	if (front == rear)
		return queueempty();  // 오류 key를 반환
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}
int main()
{
	element item;
	int menu, count, i;

	while (1)
	{
		printf("1. 삽입 2. 삭제 3. 종료 => ");
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
				addq(item);
			}
			break;
		case 2:
			printf("몇 개를 삭제? => ");
			scanf_s("%d", &count);
			for (i = 0; i < count; i++)
			{
				element temp = deleteq();
				printf("삭제: %c\n", temp.key);
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}
