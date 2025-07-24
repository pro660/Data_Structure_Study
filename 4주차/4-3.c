// 3. C언어 키워드(char, for, while 등등)를 키로 하여 
// 삽입, 검색, 삭제하는 해시 테이블 구현
// (버킷의 크기는 자유, 슬롯은 1, 제산함수, 오버플로우 처리는 선형조사법 이용)
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