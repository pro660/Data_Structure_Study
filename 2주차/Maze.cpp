/* 4. 미로 찾기(교재 그림 3.8~3.10, 프로그램 3.12) */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 1000
#define MAX_ROW 12
#define MAX_COL 15
#define EXIT_ROW 11
#define EXIT_COL 14
#define TRUE 1
#define FALSE 0
typedef struct {
	short int vert; // 행
	short int horiz; // 열
} offsets;
offsets move[8] = {	 // 각 방향에 대한 이동 배열
	{-1, 0},	// 북 (N)
	{-1, 1},	// 북동 (NE)
	{0, 1},		// 동 (E)
	{1, 1},		// 남동 (SE)
	{1, 0},		// 남 (S)
	{1, -1},	// 남서 (SW)
	{0, -1},	// 서 (W)
	{-1, -1}	// 북서 (NW)
};
typedef struct {
	short int row; // 행
	short int col; // 열
	short int dir;
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
int mark[MAX_ROW][MAX_COL] = { 0 };
int maze[MAX_ROW][MAX_COL] = {
	{ 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
	{ 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
	{ 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0 }
};
void path(void)
{	// 미로를 통과하는 경로가 있으면 그 경로를 출력한다.
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	while (top > -1 && !found)
	{
		position = pop();
		row = position.row; col = position.col;
		dir = position.dir;
		while (dir < 8 && !found)
		{	// dir 방향으로 이동
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (nextRow >= 0 && nextRow < MAX_ROW && nextCol >= 0 && nextCol < MAX_COL)
			{	// nextRow와 nextCol이 배열(미로) 범위를 벗어나지 않도록 방지.
				if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				{
					position.row = row;
					position.col = col;
					position.dir = dir;
					push(position); // 도착 전 위치 저장

					position.row = nextRow;
					position.col = nextCol;
					position.dir = 0;
					push(position); // 도착 위치 저장
					found = TRUE;
				}
				else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
				{
					mark[nextRow][nextCol] = 1;
					position.row = row; position.col = col;
					position.dir = ++dir;
					push(position);
					row = nextRow; col = nextCol; dir = 0;
				}
				else ++dir;
			}
			else ++dir;
		}
	}
	if (found)
	{
		printf("The path is:\n");
		printf("row col\n");
		for (i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("EXIT (row / col): %2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path\n");
}
int main()
{
	path();
}