/* 미로 찾기 프로그램 */
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

/** 행과 열, 변화값을 필드로 가지는 구조체 타입 */
typedef struct
{
    short int row;
    short int col;
    short int dir;
} element;

/** 미로에서 이동의 8방향을 표현하기 위한 구조체 타입 */
typedef struct 
{
    short int vert;
    short int horiz;
} offsets;

/** 미로의 길을 찾는 path 함수 */
void path(void);

void push(element item);
element pop();
void stackFull();
void stackEmpty();
/* 아 피곤하다ㅠㅠ */
/* 전역 변수 선언 */
offsets move[8] = { /* 각 방향에 대한 이동 배열 */
    {-1,  0}, // N
    {-1,  1}, // NE
    { 0,  1}, // E
    { 1,  1}, // SE
    { 1,  0}, // S
    { 1, -1}, // SW
    { 0, -1}, // W
    {-1, -1}  // NW
};

#define ROW 12
#define COL 15
#define STACK_SIZE (ROW*COL)
element stack[STACK_SIZE];
int top = -1;

int maze[ROW][COL] = {
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

/* 출구 위치 */
#define EXIT_ROW 11
#define EXIT_COL 14

/* 방문 여부를 저장하는 배열 */
int mark[ROW][COL] = {0};

int main(){

    path();
    return 0;
}

/** 미로의 길을 찾는 함수 */
void path(void){ 
    int i, row, col, nextRow, nextCol, dir, found=FALSE;
    element position;
    
    {/* 출발점은 index 0 0으로 설정 */}
    if (maze[0][0] == 0) {
        mark[0][0] = 1;
        top = -1;
        position.row = 0; position.col = 0; position.dir = 0;
        push(position);
    } else {
        printf("출발점이 벽입니다.\n");
        return;
    }
    
    while(top>-1 && !found){
        position = pop();
        row = position.row; col = position.col; dir = position.dir;
        while(dir<8 && !found){
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if(nextRow==EXIT_ROW && nextCol==EXIT_COL)
                found = TRUE;
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol] 
                    && nextRow >= 0 && nextRow < ROW && nextCol >= 0 && nextCol < COL){
                mark[nextRow][nextCol] = 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            }
            else 
                ++dir;
        }
    }
    if(found){
        printf("The path is : \n");
        printf("row  col\n");
        for(i=0; i<=top; i++)
            printf("%2d%5d\n", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else   
        printf("The maze does not have a path\n");
}

void push(element item){ //top이 사이즈-1보다 크거나 같으면 Full, 따라서 종료 or Full이 아닐 시 item 삽입

	if(top>=STACK_SIZE-1) {
		stackFull();
    }
	stack[++top] = item;
}

element pop(){
	if(top==-1) {
		stackEmpty();
    }
	return stack[top--];
}

void stackFull(){
	fprintf(stderr, "stack is Full already");
	exit(1);
}

void stackEmpty(){
	fprintf(stderr, "stack is Empty already");
	exit(1);
}