/* 문자 저장 연결리스트를 이용한 스택 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 10 // 스택의 최대 수
#define MALLOC(p, s)\
 if (! ((p) = (stackPointer)malloc(s))) {\
fprintf(stderr, "Insufficient memory");\
exit(EXIT_FAILURE);\
}
typedef struct {
	char key;
} element;
typedef struct stack* stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
};
stackPointer top[MAX_STACKS];
void push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}
element stackEmpty()
{
	element dummy = { '\0' };
	fprintf(stderr, "Stack is Empty\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
	exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
	return dummy;
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
void printStack(stackPointer first)
{
	printf("The Stack contains: ");
	for (; first; first = first->link)
		printf("%4c", first->data.key);
	printf("\n");
}
int main()
{
	element item;
	int menu, count, i;

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
				push(0, item);
			}
			break;
		case 2:
			printf("몇 개를 삭제? => ");
			scanf_s("%d", &count);
			for (i = 0; i < count; i++)
			{
				element temp = pop(0);
				printf("삭제: %c\n", temp.key);
			}
			break;
		case 3:
			printStack(top[0]); // 다중 스택에서 index 0에 해당하는 스택만 사용
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
}
