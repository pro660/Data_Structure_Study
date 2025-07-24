// 2. 힙 소트 구현(교재 프로그램 7.12, 7.13)
#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 
typedef struct {
	int key;
} element;
void adjust(element a[], int root, int n) 
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key)
			break;
		else {
			a[child / 2] = a[child];
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
	for (i = n - 1; i > 0; i--) {
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}
int main(void) {
	element rawList[] = 
	{ {26}, {5}, {77}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
	int size = sizeof(rawList) / sizeof(rawList[0]);
	element list[11];
	for (int i = 0; i < size; i++)
		list[i + 1] = rawList[i];
	printf("정렬 전: ");
	for (int i = 1; i <= size; i++)
		printf("%d ", list[i].key);
	printf("\n");
	heapSort(list, size);
	printf("정렬 후: ");
	for (int i = 1; i <= size; i++)
		printf("%d ", list[i].key);
	printf("\n");
}