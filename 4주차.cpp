//1.퀵 소트 구현 시간 복잡도 계산
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

//1.1 하이브리드 퀵 소트 구현 시간복잡도 계산
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

// 2. 힙 소트 구현
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

//3. C언어 키워드(char, for, while 등등)를 키로 하여 삽입, 검색, 삭제하는 해시 테이블 구현
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define B 11  
typedef struct {
    char item[100];
    int key;
} element;
element* ht[B] = { NULL };
element dummy = { "", -1 };
int h(int k)
{
    return k % B;
}
int stringToKey(const char* str)
{
    int key = 0;
    while (*str)
        key += *str++;
    return key;
}
void insert(int k, const char* word)
{
    int i = h(k);
    int start = i;
    while (ht[i] != NULL && ht[i]->key != -1)
    {
        i = (i + 1) % B;
        if (i == start)
        {
            printf("해시 테이블이 가득 찼습니다.\n");
            return;
        }
    }
    ht[i] = (element*)malloc(sizeof(element));
    if (ht[i] == NULL)
    {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    strcpy_s(ht[i]->item, sizeof(ht[i]->item), word);
    ht[i]->key = k;
}
element* search(int k)
{
    int homeBucket = h(k);
    int currentBucket = homeBucket;
    while (ht[currentBucket] && ht[currentBucket]->key != k)
    {
        currentBucket = (currentBucket + 1) % B;
        if (currentBucket == homeBucket)
            return NULL;
    }
    if (ht[currentBucket] && ht[currentBucket]->key == k)
        return ht[currentBucket];
    return NULL;
}
void deleteKey(int k)
{
    element* found = search(k);
    if (found)
    {
        free(found);
        found = &dummy;
    }
    else
        printf("해당 키를 찾을 수 없습니다.\n");
}
void printHashTable()
{
    printf("\n====해시 테이블 상태====\n");
    for (int i = 0; i < B; i++)
    {
        if (ht[i] && ht[i]->key != -1)
            printf("[%d] %s (key=%d)\n", i, ht[i]->item, ht[i]->key);
        else
            printf("[%d] ---\n", i);
    }
}
int main(void)
{
    insert(stringToKey("acos"), "acos");
    insert(stringToKey("atoi"), "atoi");
    insert(stringToKey("char"), "char");
    insert(stringToKey("define"), "define");
    insert(stringToKey("exp"), "exp");
    insert(stringToKey("ceil"), "ceil");
    insert(stringToKey("cos"), "cos");
    insert(stringToKey("float"), "float");
    insert(stringToKey("atol"), "atol");
    insert(stringToKey("floor"), "floor");
    insert(stringToKey("ctime"), "ctime");
    printHashTable();
    const char* word = "ceil";
    int key = stringToKey(word);
    element* result = search(key);
    if (result)
        printf("\n'%s' 검색 성공 (key=%d)\n", result->item, key);
    else
        printf("\n'%s' 검색 실패\n", word);
}