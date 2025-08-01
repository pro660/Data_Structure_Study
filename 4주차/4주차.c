/*
1. 퀵 소트 구현 (책에 나와 있는 버전-교재 프로그램 7.6)
*퀵소트 시간 복잡도 분석하기(시간 복잡도를 분석한 후, 이를 개선하기 위한 책과 다른 버전의 퀵 소트 알고리즘 찾아 구현하기)
2. 힙 소트 구현(교재 프로그램 7.12, 7.13)
3. C언어 키워드(char, for, while 등등)를 키로 하여 삽입, 검색, 삭제하는 해시 테이블 구현(버킷의 크기는 자유, 슬롯은 1, 제산함수, 오버플로우 처리는 선형조사법 이용)
*/

/* 1. 퀵 소트 구현 (책에 나와 있는 버전-교재 프로그램 7.6) */

//#include <stdio.h>
//#define MAX_LIST_SIZE 10
//#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}
//typedef struct {
//	int key;
//} element;
//void quickSort(element a[], int left, int right)
//{	/* sort a[left:right] into nondecreasing order on the key field;
//	a[left].key is arbitrarily chosen as the pivot key;
//	it is assumed that a[left].key <= a[right+1].key */
//	int pivot, i, j;
//	element temp;
//	if (left < right)
//	{
//		i = left; j = right + 1;
//		pivot = a[left].key;
//		do
//		{	/* search for keys from the left and right sublists, swapping out-of-order elements until the left and right boundaries cross or meet */
//			do i++; while (a[i].key < pivot);
//			do j--; while (a[j].key > pivot);
//			if (i < j) SWAP(a[i], a[j], temp);
//		} while (i < j);
//		SWAP(a[left], a[j], temp);
//		quickSort(a, left, j - 1);
//		quickSort(a, j + 1, right);
//	}
//}
//void printList(element a[])
//{
//	for (int i = 0; i < MAX_LIST_SIZE; i++)
//		printf("%6d", a[i].key);
//	printf("\n");
//}
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

/* 퀵 정렬 과정 출력 버전 */

//#include <stdio.h>
//#define MAX_LIST_SIZE 10
//#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}
//typedef struct {
//	int key;
//} element;
//void printList(element a[])
//{
//	for (int i = 0; i < MAX_LIST_SIZE; i++)
//		printf("%6d", a[i].key);
//	printf("\n");
//}
//void quickSort(element a[], int left, int right)
//{	/* sort a[left:right] into nondecreasing order on the key field;
//	a[left].key is arbitrarily chosen as the pivot key;
//	it is assumed that a[left].key <= a[right+1].key */
//	int pivot, i, j;
//	element temp;
//	if (left < right)
//	{
//		i = left; j = right + 1;
//		pivot = a[left].key;
//		do
//		{	/* search for keys from the left and right sublists, swapping out-of-order elements until the left and right boundaries cross or meet */
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

/* 퀵소트 시간 복잡도 분석하기(시간 복잡도를 분석한 후, 이를 개선하기 위한 책과 다른 버전의 퀵 소트 알고리즘 찾아 구현하기) */

//#include <stdio.h>
//#define MAX_LIST_SIZE 10
//#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}
//int partition(int arr[], int p, int r) {
//    int low, high;
//    int pivot = arr[p]; // pivot 값 설정
//
//    low = p + 1; // low 는 pivot의 바로 다음 위치에서부터
//    high = r; // high는 전달된 끝지점
//
//    while (low <= high) {
//        while (arr[low] < pivot) low++; // pivot 보다 작은 값이 나올때마다 이동
//        while (arr[high] > pivot) high--; // pivot 보다 큰 값이 나올때마다 이동
//
//        if (low <= high) { // low와 high 가 중단된 지점이 서로 위치가 역전된 지점이 아니라면
//            int temp = arr[low];    // low 와 high 의 값 변경
//            arr[low] = arr[high];
//            arr[high] = temp;
//        }
//    }
//
//    // 피벗과 high 위치 교환
//    int temp = arr[p];
//    arr[p] = arr[high];
//    arr[high] = temp;
//
//    return high; // 피벗 위치 반환
//
//}
//void quick_sort(int arr[], int left, int right) {
//    if (left < right) {
//        int pivot = partition(arr, left, right);
//
//        quick_sort(arr, left, pivot - 1); // 피벗을 기준으로 왼쪽 배열 정렬
//        quick_sort(arr, pivot + 1, right); // 피벗 기준으로 오른쪽 배열 정렬
//    }
//}
//void printList(int a[])
//{
//	for (int i = 0; i < MAX_LIST_SIZE; i++)
//		printf("%6d", a[i]);
//	printf("\n");
//}
//int main()
//{
//	int i;
//    int a[] = { 26, 5, 37, 1, 61, 11, 59, 15, 48, 19 };
//	printf("Before:");
//	printList(a);
//	quick_sort(a, 0, 9);
//	printf("After:");
//	printList(a);
//}

/* 2. 힙 소트 구현(교재 프로그램 7.12, 7.13) */

//#include <stdio.h>
//#define MAX_LIST_SIZE 11
//#define SWAP(x, y, t) {(t) = (x), (x) = (y), (y) = (t);}
//typedef struct {
//	int key;
//} element;
//void adjust(element a[], int root, int n)
//{	// adjust the binary tree to establish the heap
//	int child, rootkey;
//	element temp;
//	temp = a[root];
//	rootkey = a[root].key;
//	child = 2 * root; // left child
//	while (child <= n)
//	{
//		if ((child < n) && (a[child].key < a[child + 1].key))
//			child++;
//		if (rootkey > a[child].key) // compare root and max. child
//			break;
//		else
//		{
//			a[child / 2] = a[child]; // move to parent
//			child *= 2;
//		}
//	}
//	a[child / 2] = temp;
//}
//void heapSort(element a[], int n)
//{	// perform a heap sort on a[1:n]
//	int i;
//	element temp;
//
//	for (i = n / 2; i > 0; i--)
//		adjust(a, i, n);
//	for (i = n - 1; i > 0; i--)
//	{
//		SWAP(a[1], a[i + 1], temp);
//		adjust(a, 1, i);
//	}
//}
//void printList(element a[])
//{
//	for (int i = 1; i < MAX_LIST_SIZE; i++)
//		printf("%6d", a[i].key);
//	printf("\n");
//}
//int main()
//{
//	int i;
//	element a[] = { {0}, {26}, {5}, {37}, {1}, {61}, {11}, {59}, {15}, {48}, {19} };
//	printf("Before:");
//	printList(a);
//	heapSort(a, MAX_LIST_SIZE - 1);
//	printf("After:");
//	printList(a);
//}

/* 3. C언어 키워드(char, for, while 등등)를 키로 하여 삽입, 검색, 삭제하는 해시 테이블 구현
(버킷의 크기는 자유, 슬롯은 1, 제산함수, 오버플로우 처리는 선형조사법 이용) */

//#include <stdio.h>
//#include <string.h>
//#define MAX_STRING_SIZE 10
//#define MAX_BUCKET_SIZE 10
//
//typedef struct {
//	char item[MAX_STRING_SIZE];
//	int key;
//} element;
//
//element* search(int k)
//{	/* 선형 조사법 해싱 테이블 ht (각 버킷은 한 슬롯만 가짐)에서 k를 탐색.
//	이 키를 가진 쌍을 발견하면, 그 쌍을 가리키는 포인터를 반환.
//	그렇지 않으면 NULL을 반환. */
//	int homeBucket, currentBucket;
//	homeBucket = h(k);
//	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
//	{
//		currentBucket = (currentBucket + 1) % b; // treat the table as circular
//		if (currentBucket == homeBucket)
//			return NULL; // back to start point
//	}
//	if (ht[currentBucket]->key == k)
//		return ht[currentBucket];
//	return NULL;
//}
//
//int main()
//{
//
//}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_STRING_SIZE 10
//#define MAX_BUCKET_SIZE 10
//
//typedef struct {
//    char item[MAX_STRING_SIZE];
//    int key;
//} element;
//
//element* ht[MAX_BUCKET_SIZE];  // 해시 테이블: 포인터 배열
//int b = MAX_BUCKET_SIZE;       // bucket 수
//
//// 해시 함수: 제산법
//int h(int key) {
//    return key % b;
//}
//
//// 문자열을 키로 변환 (아스키 합)
//int make_key(const char* str) {
//    int sum = 0;
//    while (*str) sum += *str++;
//    return sum;
//}
//
//element* search(int k)
//{	/* 선형 조사법 해싱 테이블 ht (각 버킷은 한 슬롯만 가짐)에서 k를 탐색.
//	이 키를 가진 쌍을 발견하면, 그 쌍을 가리키는 포인터를 반환.
//	그렇지 않으면 NULL을 반환. */
//	int homeBucket, currentBucket;
//	homeBucket = h(k);
//	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
//	{
//		currentBucket = (currentBucket + 1) % b; // treat the table as circular
//		if (currentBucket == homeBucket)
//			return NULL; // back to start point
//	}
//	if (ht[currentBucket]->key == k)
//		return ht[currentBucket];
//	return NULL;
//}
//
//// 삽입 함수
//void insert(const char* str) {
//    int key = make_key(str);
//    int homeBucket = h(key);
//    int currentBucket = homeBucket;
//
//    for (int i = 0; i < b; i++) {
//        if (ht[currentBucket] == NULL) {
//            ht[currentBucket] = (element*)malloc(sizeof(element));
//            strcpy(ht[currentBucket]->item, str);
//            ht[currentBucket]->key = key;
//            printf("\"%s\" inserted at index %d\n", str, currentBucket);
//            return;
//        }
//        currentBucket = (currentBucket + 1) % b;
//        if (currentBucket == homeBucket) break;
//    }
//    printf("Hash table is full. Cannot insert \"%s\"\n", str);
//}
//
//// 삭제 함수
//void deletehash(const char* str) {
//    int key = make_key(str);
//    element* target = search(key);  // 사용자가 작성한 search 함수 사용
//    if (target != NULL && strcmp(target->item, str) == 0) {
//        int idx = h(key);
//        while (ht[idx] != NULL) {
//            if (ht[idx]->key == key && strcmp(ht[idx]->item, str) == 0) {
//                free(ht[idx]);
//                ht[idx] = NULL;
//                printf("\"%s\" deleted from index %d\n", str, idx);
//                return;
//            }
//            idx = (idx + 1) % b;
//        }
//    }
//    printf("\"%s\" not found\n", str);
//}
//
//// 해시 테이블 출력
//void print_table() {
//    printf("\nHash Table:\n");
//    for (int i = 0; i < b; i++) {
//        if (ht[i] != NULL)
//            printf("[%d] %s (key=%d)\n", i, ht[i]->item, ht[i]->key);
//        else
//            printf("[%d] (empty)\n", i);
//    }
//}
//
//int main() {
//    // 삽입
//    insert("char");
//    insert("int");
//    insert("for");
//    insert("while");
//    insert("if");
//    insert("else");
//    insert("return");
//    insert("float");
//    insert("double");
//    insert("break");
//
//    print_table();
//
//    // 검색: "while"
//    int key = make_key("while");
//    element* result = search(key);  // 당신이 작성한 search(k) 함수 사용
//    if (result != NULL && strcmp(result->item, "while") == 0)
//        printf("\n\"while\" found: item = %s, key = %d\n", result->item, result->key);
//    else
//        printf("\n\"while\" not found\n");
//
//    // 삭제
//    deletehash("while");
//    deletehash("main");  // 존재하지 않는 키
//
//    // 최종 출력
//    print_table();
//
//    return 0;
//}
