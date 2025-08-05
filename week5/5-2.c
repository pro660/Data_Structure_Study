#include <stdio.h>
#define INF 1000000 // 매우 큰 수로 초기화

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int coins[], int n, int amount) {
    int dp[amount + 1];

    // 초기화: 모든 값을 큰 수로 설정
    for (int i = 0; i <= amount; i++)
        dp[i] = INF;
    dp[0] = 0; // 0원을 만들기 위한 동전 개수는 0

    // Bottom-up DP
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = coinChange(coins, n, amount);
    if (result != -1)
        printf("최소 동전 개수: %d\n", result);
    else
        printf("해당 금액을 만들 수 없습니다.\n");

    return 0;
}
