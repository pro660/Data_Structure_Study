/* 문자 저장 배열을 이용한 스택 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10 // 최대 스택 크기
typedef struct
{
	char key;
} element;
element stack[MAX_STACK_SIZE];
int top = -1;
// Boolean IsEmpty (Stack) ::= top < 0;
// Boolean IsFull (Stack) ::= top >= MAX_STACK_SIZE - 1;
void stackFull()
{
	fprintf(stderr, "Stack is Full\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
}
element stackEmpty()
{
	element dummy = { '\0' };
	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
	return dummy;
}
void push(element item)
{ // 전역 stack에 item을 삽입
	if (top >= MAX_STACK_SIZE - 1) // 스택이 다 찼는지 확인
		stackFull();
	stack[++top] = item;
}
element pop()
{ // stack의 최상의 원소를 반환
	if (top == -1) // 스택이 있는지 확인
		return stackEmpty(); // 오류 Key를 반환
	return stack[top--];
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
				push(item);
			}
			break;
		case 2:
			printf("몇 개를 삭제? => ");
			scanf_s("%d", &count);
			for (i = 0; i < count; i++)
			{
				element temp = pop();
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
