//1.분할 정복을 사용하여 최대 구간 합 찾기
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxCrossSum(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = -1000000;
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }
    sum = 0;
    int rightSum = -1000000;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int arr[], int left, int right)
{
    if (left == right) return arr[left];
    int mid = (left + right) / 2;
    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int crossMax = maxCrossSum(arr, left, mid, right);
    return MAX(MAX(leftMax, rightMax), crossMax);
}
int main()
{
    int arr[] = { 2, -4, 3, -1, 2, -4, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = maxSubArraySum(arr, 0, size - 1);
    printf("최대 구간 합: %d\n", result);
}

//2.동적 계산법을 이용하여 최단 경로 알고리즘 사용
#include <stdio.h>
#define INF 1000000000
int main(void)
{
    int n = 4;
    int dist[4][4] =
    {
        {0,     5,   INF, 8},
        {7,     0,   9,   INF},
        {2,     INF, 0,   4},
        {INF,   INF, 3,   0}
    };
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("모든 정점 쌍의 최단 경로 길이:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}