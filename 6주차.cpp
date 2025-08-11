//1. 탐욕 알고리즘을 사용한 거스름돈 계산 알고리즘
#include <stdio.h>
int main() {
    int coins[] = { 500, 100, 50, 10 };  // 사용 가능한 동전 종류
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int amount;  // 거슬러 줄 금액

    printf("거슬러 줄 금액을 입력하세요: ");
    scanf_s("%d", &amount);

    printf("거슬러 줄 방법 (탐욕 알고리즘 사용):\n");

    for (int i = 0; i < num_coins; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];
            amount = amount % coins[i];
            printf("%d원: %d개\n", coins[i], count);
        }
    }

    if (amount > 0) {
        printf("남은 금액 %d원은 거슬러 줄 수 없습니다.\n", amount);
    }

    return 0;
}

//2. 체스판에 n개의 퀸을 서로 공격하지 않도록 놓는 방법을 찾는 
//   백트래킹 알고리즘
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* board;
int N;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0; // 같은 열 또는 대각선에 있음
        }
    }
    return 1; // 안전함
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        printSolution(); // 하나의 해를 찾음
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("N-Queen 문제의 N값을 입력하세요: ");
    scanf_s("%d", &N);

    board = (int*)malloc(sizeof(int) * N);
    solve(0);
    free(board);
    return 0;
}
