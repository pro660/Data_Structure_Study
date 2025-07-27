/* 1. 퀵 소트(교재 프로그램 7.6) 및 시간복잡도 분석/개선하기 위한 다른 버전의 퀵 소트 알고리즘 찾아 구현하기 */

/* 교재버전 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y, temp) { temp = x; x = y; y = temp; }

typedef struct {
    int key;
} element;

void quickSort(element a[], int left, int right) {
    int pivot, i, j;
    element temp;

    if(left < right) {
        i = left; j = right + 1;
        pivot = a[left].key;
        do {
            do i++; while(a[i].key < pivot);
            do j--; while(a[j].key > pivot);
            if(i < j) SWAP(a[i], a[j], temp);
        } while(i < j);
        SWAP(a[left], a[j], temp);
        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
    }
}

void inputElements(element a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter key for element %d: ", i + 1);
        scanf("%d", &a[i].key);
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    element *a = (element *)malloc(n * sizeof(element));
    if(a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // 비정상 종료(메모리 할당 실패)
    }

    inputElements(a, n);
    
    clock_t start = clock();
    quickSort(a, 0, n - 1);
    clock_t end = clock();

    printf("Sorted elements:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i].key);
    }
    printf("\n");

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);

    free(a);
    return 0;
}
///////////////////////////////
/* 2. 퀵 소트 알고리즘의 다른 버전 구현하기 */

/* Dual-Pivot Quicksort */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INSERTION_THRESHOLD 11 // 삽입 정렬로 전환할 임계값
#define SWAP(x, y, temp) { temp = x; x = y; y = temp; }

typedef struct {
    int key;
} element;

void insertionSort(element arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        element t = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].key > t.key) {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = t;
    }
}

void dualPivotQuickSort(element arr[], int left, int right) {
    int size = right - left + 1;
    if (size < INSERTION_THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }

    element tmp;
    // 두 피벗 선택 (p1 ≤ p2 보장)
    if (arr[left].key > arr[right].key) {
        SWAP(arr[left], arr[right], tmp);
    }
    element p1 = arr[left], p2 = arr[right];

    int lt = left + 1, gt = right - 1, i = lt;
    while (i <= gt) {
        if (arr[i].key < p1.key) {
            SWAP(arr[i++], arr[lt++], tmp);
        }
        else if (arr[i].key > p2.key) {
            SWAP(arr[i], arr[gt--], tmp);
        }
        else {
            ++i;
        }
    }

    // 피벗을 제자리로
    SWAP(arr[left], arr[--lt], tmp);
    SWAP(arr[right], arr[++gt], tmp);

    // 세 구간 재귀 정렬
    dualPivotQuickSort(arr, left, lt - 1);
    dualPivotQuickSort(arr, gt + 1, right);
    if (p1.key < p2.key) {
        dualPivotQuickSort(arr, lt + 1, gt - 1);
    }
}

// 진입 함수
void sort(element arr[], int n) {
    if (n > 1) {
        dualPivotQuickSort(arr, 0, n - 1);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    element *arr = malloc(n * sizeof(element));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter elements (keys only):");
        scanf("%d", &arr[i].key);
    }

    clock_t start = clock();
    sort(arr, n);
    clock_t end = clock();

    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].key);
    }
    printf("\n");

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);

    free(arr);
    return 0;
}
