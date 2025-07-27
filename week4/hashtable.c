#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 슬롯 상태 */
#define EMPTY    0
#define OCCUPIED 1
#define DELETED  2

/* 해시 테이블 크기 (소수 권장) */
#define TABLE_SIZE 97

/* 슬롯 구조체 */
typedef struct {
    char *key;
    int state;
} HashSlot;

/* 전역 해시 테이블 */
static HashSlot table[TABLE_SIZE];

/* 초기화 */
void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key   = NULL;
        table[i].state = EMPTY;
    }
}

/* 단순 해시 함수: 문자열 아스키 합 % TABLE_SIZE */
int hash(const char *s) {
    unsigned sum = 0;
    while (*s) sum += (unsigned char)(*s++);
    return sum % TABLE_SIZE;
}

/* 삽입: 성공하면 인덱스, 실패(-1) */
int hash_insert(const char *key) {
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int cur = (idx + i) % TABLE_SIZE;
        if (table[cur].state == OCCUPIED) {
            if (strcmp(table[cur].key, key) == 0) {
                return cur; // 이미 존재
            }
        }
        else {
            // EMPTY or DELETED 자리
            if (table[cur].state == DELETED && table[cur].key) {
                free(table[cur].key);
            }
            table[cur].key   = malloc(strlen(key) + 1);
            if (!table[cur].key) {
                fprintf(stderr, "메모리 할당 실패\n");
                exit(1);
            }
            strcpy(table[cur].key, key);
            table[cur].state = OCCUPIED;
            return cur;
        }
    }
    return -1; // 테이블이 가득 참
}

/* 검색: 찾으면 index, 못 찾으면 -1 */
int hash_search(const char *key) {
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int cur = (idx + i) % TABLE_SIZE;
        if (table[cur].state == EMPTY) {
            return -1; // 빈 슬롯 만나면 탐색 종료
        }
        if (table[cur].state == OCCUPIED &&
            strcmp(table[cur].key, key) == 0) {
            return cur;
        }
        // DELETED면 계속 진행
    }
    return -1;
}

/* 삭제: 성공 1, 실패 0 */
int hash_delete(const char *key) {
    int pos = hash_search(key);
    if (pos < 0) return 0;

    free(table[pos].key);
    table[pos].key   = NULL;
    table[pos].state = DELETED;
    return 1;
}

/* 테이블 출력 */
void display_table() {
    puts("\n====== Hash Table ======");
    puts("Index | State    | Key");
    puts("------+----------+----------------");
    for (int i = 0; i < TABLE_SIZE; i++) {
        const char *st = 
            table[i].state == EMPTY    ? "EMPTY" :
            table[i].state == OCCUPIED ? "OCCUPIED" : "DELETED";
        printf("%5d | %8s | %s\n",
               i, st, table[i].key ? table[i].key : "-");
    }
    puts("==========================\n");
}

/* 종료 전 메모리 정리 */
void cleanup_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].state == OCCUPIED && table[i].key) {
            free(table[i].key);
            table[i].key = NULL;
        }
    }
}

int main(void) {
    char buf[64];
    int choice, idx;

    init_table();

    while (1) {
        printf("1) insert  2) search  3) delete  4) view table  5) exit\n");
        printf("press number> ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:  // 삽입
                printf("Enter the key to insert : ");
                scanf("%63s", buf);
                idx = hash_insert(buf);
                if (idx < 0) {
                    puts("Table is full, cannot insert.");
                } else {
                    printf("'%s' Insertion complete (index=%d)\n", buf, idx);
                }
                display_table();
                break;

            case 2:  // 검색
                printf("Enter the key to search : ");
                scanf("%63s", buf);
                idx = hash_search(buf);
                if (idx < 0) {
                    printf("cannot find'%s'\n", buf);
                } else {
                    printf("find '%s' to index %d.\n", buf, idx);
                }
                break;

            case 3:  // 삭제
                printf("Enter the key to delete : ");
                scanf("%63s", buf);
                if (hash_delete(buf)) {
                    printf("'%s' delete complete \n", buf);
                } else {
                    printf("cannot find'%s', delete fail\n", buf);
                }
                display_table();
                break;

            case 4:  // 전체 출력
                display_table();
                break;

            case 5:  // 종료
                cleanup_table();
                puts("exit program.");
                return 0;

            default:
                puts("Enter other numbers.");
        }
    }

    cleanup_table();
    return 0;
}
