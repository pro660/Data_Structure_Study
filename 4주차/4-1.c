// 1. 퀵 소트 구현 (책에 나와 있는 버전-교재 프로그램 7.6)
// * 퀵소트 시간 복잡도 분석하기
// (시간 복잡도를 분석한 후, 이를 개선하기 위한 책과 다른 버전의 퀵 소트 알고리즘 찾아 구현하기)
// 1.1 퀵 소트 구현 (책에 나와 있는 버전-교재 프로그램 7.6)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 
typedef struct {
	int key;
} element;
void quickSort(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = a[left].key;
		do {
			do i++; while (i <= right && a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);
		SWAP(a[left], a[j], temp);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}
int main(void) {
	element list[] = 
	{ {26}, {5}, {77}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
	int size = sizeof(list) / sizeof(list[0]);
	printf("정렬 전: ");
	for (int i = 0; i < size; i++)
		printf("%d ", list[i].key);
	printf("\n");
	clock_t start = clock();
	quickSort(list, 0, size - 1);
	clock_t end = clock();
	double time_taken = (double)(end - start)
        / CLOCKS_PER_SEC * 1000; 
	printf("정렬 후: ");
	for (int i = 0; i < size; i++)
		printf("%d ", list[i].key);
	printf("\n");
	printf("O(n) : %.3f\n", time_taken);
}

// 1.2 개선하기 위한 책과 다른 버전의 퀵 소트 알고리즘 찾아 구현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 
typedef struct {
    int key;
} element;
#define THRESHOLD 10  
void insertionSort(element a[], int left, int right) 
{
    int i, j;
    element temp;
    for (i = left + 1; i <= right; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= left && a[j].key > temp.key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
void hybridQuickSort(element a[], int left, int right)
{
    int pivot, i, j;
    element temp;
    if (right - left + 1 <= THRESHOLD) 
    {
        insertionSort(a, left, right);
        return;
    }
    if (left < right) 
    {
        i = left;
        j = right + 1;
        pivot = a[left].key;
        do {
            do i++; while (i <= right && a[i].key < pivot);
            do j--; while (a[j].key > pivot);
            if (i < j) SWAP(a[i], a[j], temp);
        } while (i < j);
        SWAP(a[left], a[j], temp);
        hybridQuickSort(a, left, j - 1);
        hybridQuickSort(a, j + 1, right);
    }
}
int main(void) {
    element list[] = 
    { {26}, {5}, {77}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
    int size = sizeof(list) / sizeof(list[0]);
    printf("정렬 전: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i].key);
    printf("\n");
    clock_t start = clock();
    hybridQuickSort(list, 0, size - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("정렬 후: ");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i].key);
    printf("\n");
    printf("O(n) : %.3f\n", time_taken);
}