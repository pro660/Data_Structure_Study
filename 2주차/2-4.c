// 4. 미로찾기 ( 교재 그림 3.8 ~ 3.10 , 프로그램 3.12 )
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
	short int row;
	short int col;
	short int dir;
}element;
typedef struct {
	int vert;
	int horiz;
} offset;
element stack[MAX_STACK_SIZE];
int top = -1;
int mark[MAX_ROW][MAX_COL] = { 0 };
int maze[MAX_ROW][MAX_COL] = {
	{0,1,0,0,0,1,1,0,0,0,1,1,1,1,1},
	{1,0,0,0,1,1,0,1,1,1,0,0,1,1,1},
	{0,1,1,0,0,0,0,1,1,1,1,0,0,1,1},
	{1,1,0,1,1,1,1,0,1,1,0,1,1,0,0},
	{1,1,0,1,0,0,1,0,1,1,1,1,1,1,1},
	{0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
	{0,0,1,1,0,1,1,1,0,1,0,0,1,0,1},
	{0,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
	{0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
	{1,1,0,0,0,1,1,0,1,1,0,0,0,0,0},
	{0,0,1,1,1,1,1,0,0,0,1,1,1,1,0},
	{0,1,0,0,1,1,1,1,1,0,1,1,1,1,0}
};
offset move[8] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};
void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1) 
	{
		printf("스택이 가득 찼습니다.\n");
		exit(1);
	}
	stack[++top] = item;
}
element pop() 
{
	if (top < 0) 
	{
		printf("스택이 비어있습니다.\n");
		exit(1);
	}
	return stack[top--];
}
void path(void)
{
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
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow < 0 || nextRow >= MAX_ROW || nextCol < 0 || nextCol >= MAX_COL) 
            {
                ++dir;
                continue;
            }
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
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
    }
    if (found)
    {
        printf("The path is:\n");
        printf("row col\n");
        for (i = 0; i <= top; i++)
            printf("%2d%5d", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else
        printf("The maze does not have a path\n");
}
int main(void) { path(); }