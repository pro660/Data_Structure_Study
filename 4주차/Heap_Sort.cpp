/* 2. 힙 소트 구현(교재 프로그램 7.12, 7.13) */

#include <stdio.h>
#define MAX_LIST_SIZE 11
#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}

typedef struct
{
	int key;
} element;

void adjust(element a[], int root, int n)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root; // 왼쪽 자식 노드.
	while (child <= n)
	{
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key) // 루트와 최대값 비교.
			break;
		else
		{
			a[child / 2] = a[child]; // 부모로 이동.
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void heapSort(element a[], int n)
{
	int i;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	for (i = n - 1; i > 0; i--)
	{
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}

void printList(element a[])
{
	for (int i = 1; i < MAX_LIST_SIZE; i++)
		printf("%6d", a[i].key);
	printf("\n");
}

int main()
{
	int i;
	element a[] = { {0}, {26}, {5}, {37}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
	printf("Before:");
	printList(a);
	heapSort(a, MAX_LIST_SIZE - 1);
	printf("After:");
	printList(a);
}