// 백 트랙킹을 이용해서 스도쿠 풀이하기
#include <stdio.h>
#define SIZE 9
int board[SIZE][SIZE]; 
int isValid(int row, int col, int num)
{
    for (int x = 0; x < SIZE; x++)
        if (board[row][x] == num) return 0;
    for (int x = 0; x < SIZE; x++)
        if (board[x][col] == num) return 0;
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return 0;
    return 1;
}
int solveSudoku() 
{
    for (int row = 0; row < SIZE; row++) 
    {
        for (int col = 0; col < SIZE; col++) 
        {
            if (board[row][col] == 0) 
            {
                for (int num = 1; num <= 9; num++) 
                {
                    if (isValid(row, col, num)) 
                    {
                        board[row][col] = num;
                        if (solveSudoku())
                            return 1;
                        board[row][col] = 0;
                    }
                }
                return 0; 
            }
        }
    }
    return 1;
}
void printBoard() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int input[SIZE][SIZE] = 
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = input[i][j];
    if (solveSudoku()) 
    {
        printf("해결된 스도쿠 보드:\n");
        printBoard();
    }
    else 
    {
        printf("해결할 수 없습니다.\n");
    }
}
