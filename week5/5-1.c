/* 분할 정복 */
#include <stdio.h>

// 분할정복으로 배열의 최댓값을 찾는 함수
int findMax(int arr[], int left, int right) {
    // 원소가 하나뿐이면 그 값 반환
    if (left == right)
        return arr[left];

    // 중간 인덱스 계산
    int mid = (left + right) / 2;

    // 좌측, 우측 배열의 최대값을 재귀적으로 찾음
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    // 둘 중 큰 값 반환
    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int arr[] = {12, 45, 23, 67, 34, 89, 10, 90, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = findMax(arr, 0, n - 1);

    printf("배열에서 최댓값은: %d\n", maxVal);
    return 0;
}
