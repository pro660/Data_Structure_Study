// 분할 정복을 이용하여 최대 구간 합 찾기
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
