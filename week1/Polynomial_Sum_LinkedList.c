#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y)((x)<(y)?-1:(x)==(y)?0:1)
#define MALLOC(p,s)\
    if(!((p) = (polyPointer)malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

typedef struct polyNode *polyPointer;
typedef struct polyNode {
    int coef;
    int expon;
    polyPointer link;
} polyNode;

// 함수 선언
polyPointer padd(polyPointer a, polyPointer b);
void attach(int coefficient, int exponent, polyPointer *ptr);
void printList(polyPointer p);

int main() {
    polyPointer a = NULL, b = NULL; 

    int coef, expon;

    printf("첫 번째 다항식 입력 (계수와 지수 입력, 0 0 입력 시 종료):\n");
    while (1) {
        printf("계수 지수: ");
        scanf("%d %d", &coef, &expon);
        if (coef == 0 && expon == 0) break;
        attach(coef, expon, &a);
    }

    printf("두 번째 다항식 입력 (계수와 지수 입력, 0 0 입력 시 종료):\n");
    while (1) {
        printf("계수 지수: ");
        scanf("%d %d", &coef, &expon);
        if (coef == 0 && expon == 0) break;
        attach(coef, expon, &b);
    }

    printf("\n첫 번째 다항식: ");
    printList(a);
    printf("두 번째 다항식: ");
    printList(b);

    polyPointer result = padd(a, b);
    printf("결과 다항식: ");
    printList(result);

    return 0;
}

polyPointer padd(polyPointer a, polyPointer b) {
    polyPointer c = NULL;
    polyPointer rear = NULL;
    int sum;

    while (a && b) {
        switch (COMPARE(a->expon, b->expon)) {
            case -1:
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum)
                    attach(sum, a->expon, &rear);
                a = a->link;
                b = b->link;
                break;
            case 1:
                attach(a->coef, a->expon, &rear);
                a = a->link;
        }
        if (!c) c = rear;
    }

    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);

    return c;
}

void attach(int coefficient, int exponent, polyPointer *ptr) {
    polyPointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->coef = coefficient;
    temp->expon = exponent;
    temp->link = NULL;

    if (*ptr) {
        polyPointer rear = *ptr;
        while (rear->link) rear = rear->link;
        rear->link = temp;
    } else {
        *ptr = temp;
    }
}

void printList(polyPointer p) {
    while (p) {
        printf("%dx^%d", p->coef, p->expon);
        p = p->link;
        if (p) printf(" + ");
    }
    printf("\n");
}

