/* 1. 퀵 소트 구현 (책에 나와 있는 버전-교재 프로그램 7.6) */

#include <stdio.h>
#define MAX_LIST_SIZE 10
#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}

typedef struct
{
	int key;
} element;

void quickSort(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if (left < right)
	{
		i = left; j = right + 1;
		pivot = a[left].key;
		do
		{
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);
		SWAP(a[left], a[j], temp);
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

void printList(element a[])
{
	for (int i = 0; i < MAX_LIST_SIZE; i++)
		printf("%6d", a[i].key);
	printf("\n");
}

int main()
{
	int i;
	element a[] = { {26}, {5}, {37}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
	printf("Before:");
	printList(a);
	quickSort(a, 0, 9);
	printf("After:");
	printList(a);
}

/* 퀵 정렬 과정 출력 버전 */

//#include <stdio.h>
//#define MAX_LIST_SIZE 10
//#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}
// 
//typedef struct {
//	int key;
//} element;
// 
//void printList(element a[])
//{
//	for (int i = 0; i < MAX_LIST_SIZE; i++)
//		printf("%6d", a[i].key);
//	printf("\n");
//}
// 
//void quickSort(element a[], int left, int right)
//{
//	int pivot, i, j;
//	element temp;
//	if (left < right)
//	{
//		i = left; j = right + 1;
//		pivot = a[left].key;
//		do
//		{
//			do i++; while (a[i].key < pivot);
//			do j--; while (a[j].key > pivot);
//			if (i < j) SWAP(a[i], a[j], temp);
//			printList(a);
//		} while (i < j);
//		SWAP(a[left], a[j], temp);
//		quickSort(a, left, j - 1);
//		quickSort(a, j + 1, right);
//	}
//}
// 
//int main()
//{
//	int i;
//	element a[] = { {26}, {5}, {37}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
//	printf("Before:");
//	printList(a);
//	quickSort(a, 0, 9);
//	printf("After:");
//	printList(a);
//}
