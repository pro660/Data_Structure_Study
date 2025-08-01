/* 3. C언어 키워드(char, for, while 등등)를 키로 하여 삽입, 검색, 삭제하는 해시 테이블 구현
(버킷의 크기는 자유, 슬롯은 1, 제산함수, 오버플로우 처리는 선형조사법 이용) */

#define _CRT_SECURE_NO_WARNINGS // Visual Studio에서 보안 경고를 무시.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 10
#define MAX_BUCKET_SIZE 10

typedef struct
{
    char item[MAX_STRING_SIZE];
    int key;
} element;

element* ht[MAX_BUCKET_SIZE];   // 해시 테이블: 포인터 배열
int b = MAX_BUCKET_SIZE;        // bucket 수

int h(int key)
{   // 제산 함수
    return key % b;
}

int make_key(const char* str)
{   // 문자열을 키로 변환 (아스키 합)
    int sum = 0;
    while (*str) sum += *str++;
    return sum;
}

element* search(int k)
{	/* 선형 조사법 해싱 테이블 ht (각 버킷은 한 슬롯만 가짐)에서 k를 탐색.
	이 키를 가진 쌍을 발견하면, 그 쌍을 가리키는 포인터를 반환.
	그렇지 않으면 NULL을 반환. */
	int homeBucket, currentBucket;
	homeBucket = h(k);
	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;)
	{
		currentBucket = (currentBucket + 1) % b; // treat the table as circular
		if (currentBucket == homeBucket)
			return NULL; // back to start point
	}
	if (ht[currentBucket]->key == k)
		return ht[currentBucket];
	return NULL;
}

void insert(const char* str)
{   // 삽입 함수
    int key = make_key(str);
    int homeBucket = h(key);
    int currentBucket = homeBucket;

    for (int i = 0; i < b; i++) {
        if (ht[currentBucket] == NULL) {
            ht[currentBucket] = (element*)malloc(sizeof(element));
            strcpy(ht[currentBucket]->item, str);
            ht[currentBucket]->key = key;
            printf("\"%s\" inserted at index %d\n", str, currentBucket);
            return;
        }
        currentBucket = (currentBucket + 1) % b;
        if (currentBucket == homeBucket) break;
    }
    printf("Hash table is full. Cannot insert \"%s\"\n", str);
}

void deletehash(const char* str)
{   // 삭제 함수
    int key = make_key(str);
    element* target = search(key);
    if (target != NULL && strcmp(target->item, str) == 0) {
        int idx = h(key);
        while (ht[idx] != NULL) {
            if (ht[idx]->key == key && strcmp(ht[idx]->item, str) == 0) {
                free(ht[idx]);
                ht[idx] = NULL;
                printf("\"%s\" deleted from index %d\n", str, idx);
                return;
            }
            idx = (idx + 1) % b;
        }
    }
    printf("\"%s\" not found\n", str);
}

void print_table()
{   // 해시 테이블 출력
    printf("\nHash Table:\n");
    for (int i = 0; i < b; i++) {
        if (ht[i] != NULL)
            printf("[%d] %s (key=%d)\n", i, ht[i]->item, ht[i]->key);
        else
            printf("[%d] (empty)\n", i);
    }
}

int main()
{
    // 삽입
    insert("char");
    insert("int");
    insert("for");
    insert("while");
    insert("if");
    insert("else");
    insert("return");
    insert("float");
    insert("double");
    insert("break");

    print_table();

    // 검색: "while"
    int key = make_key("while");
    element* result = search(key);
    if (result != NULL && strcmp(result->item, "while") == 0)
        printf("\n\"while\" found: item = %s, key = %d\n", result->item, result->key);
    else
        printf("\n\"while\" not found\n");

    // 삭제
    deletehash("while");
    deletehash("main");  // 존재하지 않는 키

    // 최종 출력
    print_table();

    return 0;
}