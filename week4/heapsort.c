/* 힙 소트 구현 */
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, temp)  \
    do {                  \
        temp = x;         \
        x    = y;         \
        y    = temp;      \
    } while (0)

typedef struct {
    int key;
} element;

// 힙의 root 위치를 재정렬하는 함수
// a[1..n] 범위에서 a[root]를 내려보내며 최대 힙 성질 복구
void adjust(element a[], int root, int n) {
    element temp = a[root];
    int rootKey = temp.key;
    int child = root * 2;

    while (child <= n) {
        // 오른쪽 자식이 있고, 오른쪽 자식이 더 크면 child를 오른쪽으로
        if (child < n && a[child].key < a[child + 1].key) {
            child++;
        }
        // rootKey가 자식보다 크면 힙 성질 만족
        if (rootKey >= a[child].key) {
            break;
        }
        // 자식을 한 단계 위로 끌어올림
        a[child / 2] = a[child];
        child *= 2;
    }
    // 원래 root 값을 최종 위치에 배치
    a[child / 2] = temp;
}

// 힙 정렬: 1번 인덱스부터 n번 인덱스까지
void heapsort(element a[], int n) {
    element temp;

    // 1) 최대 힙 구성
    for (int i = n / 2; i >= 1; i--) {
        adjust(a, i, n);
    }

    // 2) 힙에서 루트(최댓값)를 꺼내 뒤로 보내고, 힙 크기를 1 줄여 재조정
    for (int i = n; i > 1; i--) {
        SWAP(a[1], a[i], temp);
        adjust(a, 1, i - 1);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    // 1-based 인덱싱을 위해 n+1 크기로 할당
    element *a = malloc((n + 1) * sizeof(element));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("Enter elements(only key) : ");
        scanf("%d", &a[i].key);
    }

    heapsort(a, n);

    printf("Sorted elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i].key);
    }
    printf("\n");

    free(a);
    return 0;
}
