//배열을 사용한 스택
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    char data[MAX_SIZE];
    int top;
} CircularStack;

void initStack(CircularStack* s) {
    s->top = -1;
}

int isStackFull(CircularStack* s) {
    return (s->top + 1) % MAX_SIZE == 0 && s->top != -1;
}

int isStackEmpty(CircularStack* s) {
    return s->top == -1;
}

void push(CircularStack* s, char item) {
    if (isStackFull(s)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    s->top = (s->top + 1) % MAX_SIZE;
    s->data[s->top] = item;
    printf("PUSH: %c\n", item);
}

char pop(CircularStack* s) {
    if (isStackEmpty(s)) {
        printf("스택이 비었습니다.\n");
        return '\0';
    }
    char item = s->data[s->top];
    if (s->top == 0)
        s->top = -1;
    else
        s->top = (s->top - 1 + MAX_SIZE) % MAX_SIZE;
    printf("POP: %c\n", item);
    return item;
}

void printStack(CircularStack* s) {
    if (isStackEmpty(s)) {
        printf("스택이 비어있습니다.\n");
        return;
    }

    printf("스택: ");
    int i = s->top;
    int count = 0;
    while (count < MAX_SIZE && i >= 0) {
        printf("%c ", s->data[i]);
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        count++;
        if (i == s->top)
            break;
    }
    printf("\n");
}

//배열을 사용한 큐
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 5
//
//typedef struct {
//    char data[MAX_SIZE];
//    int front;
//    int rear;
//} CircularQueue;
//
//void initQueue(CircularQueue* q) {
//    q->front = 0;
//    q->rear = 0;
//}
//
//int isQueueEmpty(CircularQueue* q) {
//    return q->front == q->rear;
//}
//
//int isQueueFull(CircularQueue* q) {
//    return (q->rear + 1) % MAX_SIZE == q->front;
//}
//
//void enqueue(CircularQueue* q, char item) {
//    if (isQueueFull(q)) {
//        printf("큐가 가득 찼습니다.\n");
//        return;
//    }
//    q->rear = (q->rear + 1) % MAX_SIZE;
//    q->data[q->rear] = item;
//    printf("ENQUEUE: %c\n", item);
//}
//
//char dequeue(CircularQueue* q) {
//    if (isQueueEmpty(q)) {
//        printf("큐가 비었습니다.\n");
//        return '\0';
//    }
//    q->front = (q->front + 1) % MAX_SIZE;
//    char item = q->data[q->front];
//    printf("DEQUEUE: %c\n", item);
//    return item;
//}
//
//void printQueue(CircularQueue* q) {
//    if (isQueueEmpty(q)) {
//        printf("큐가 비어있습니다.\n");
//        return;
//    }
//
//    printf("큐: ");
//    int i = (q->front + 1) % MAX_SIZE;
//    while (i != (q->rear + 1) % MAX_SIZE) {
//        printf("%c ", q->data[i]);
//        i = (i + 1) % MAX_SIZE;
//    }
//    printf("\n");
//}

//동적 연결 스택 
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#define MALLOC(p, s)\
// if (! ((p) = (stackPointer)malloc(s))) {\
//fprintf(stderr, "Insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct {
//    char key;
//} element;
//typedef struct stack* stackPointer;
//typedef struct stack {
//    element data;
//    stackPointer link;
//} stack;
//stackPointer top;
//void push(element item)
//{
//    stackPointer temp;
//    MALLOC(temp, sizeof(*temp));
//    temp->data = item;
//    temp->link = top;
//    top = temp;
//}
//element stackEmpty()
//{
//    element dummy = { '\0' };
//    fprintf(stderr, "Stack is Empty\n");
//    exit(EXIT_FAILURE);
//    return dummy;
//}
//element pop()
//{
//    stackPointer temp = top;
//    element item;
//    if (!temp)
//        return stackEmpty();
//    item = temp->data;
//    top = temp->link;
//    free(temp);
//    return item;
//}
//void printStack(stackPointer first)
//{
//    printf("The Stack contains: ");
//    for (; first; first = first->link)
//        printf("%4d", first->data);
//    printf("\n");
//}
//void main()
//{
//    element item1 = { 1 };
//
//    push(item1);
//    printStack(top);
//    printf("%d\n", pop());
//    printStack(top);
//}

//동적 연결 큐 
//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#define MALLOC(p, s)\
// if (! ((p) = (queuePointer)malloc(s))) {\
//fprintf(stderr, "insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct {
//    char key;
//} element;
//typedef struct queue* queuePointer;
//typedef struct queue {
//    element data;
//    queuePointer link;
//} queue;
//queuePointer front, rear;
//void addq(element item)
//{
//    queuePointer temp;
//    MALLOC(temp, sizeof(*temp));
//    temp->data = item;
//    temp->link = NULL;
//    if (front)
//        rear->link = temp;
//    else
//        front = temp;
//    rear = temp;
//}
//element queueEmpty()
//{
//    element dummy = { '\0' };
//    printf(stderr, "queue is empty\n");
//    exit(1);
//}
//element deleteq()
//{
//    queuePointer temp = front;
//    element item;
//    if (!temp)
//        return queueEmpty();
//    item = temp->data;
//    front = temp->link;
//    free(temp);
//    return item;
//}
//void printQueue(queuePointer first)
//{
//    printf("the queue contains: ");
//    for (; first; first = first->link)
//        printf("%4d", first->data);
//    printf("\n");
//}
//void main()
//{
//    element item1 = { 1 };
//    addq(item1);
//    printQueue(rear);
//    printQueue(front);
//    printf("%d", deleteq());
//}

//다항식의 배열
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 100
//#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1)
//    typedef struct
//{
//    float coef;
//    int expon;
//} polynomial;
//polynomial terms[MAX_TERMS];
//int avail = 0;
//void attach(float coefficient, int exponent)
//{
//    if (avail >= MAX_TERMS)
//    {
//        fprintf(stderr, "다항식에 항이 너무 많다.\n");
//        exit(1);
//    }
//    terms[avail].coef = coefficient;
//    terms[avail++].expon = exponent;
//}
//void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
//{
//    float coefficient;
//    *startD = avail;
//
//    while (startA <= finishA && startB <= finishB)
//    {
//        switch (COMPARE(terms[startA].expon, terms[startB].expon))
//        {
//        case -1:
//            attach(terms[startB].coef, terms[startB].expon);
//            startB++;
//            break;
//        case 0:
//            coefficient = terms[startA].coef + terms[startB].coef;
//            if (coefficient)
//                attach(coefficient, terms[startA].expon);
//            startA++;
//            startB++;
//            break;
//        case 1:
//            attach(terms[startA].coef, terms[startA].expon);
//            startA++;
//        }
//    }
//
//    for (; startA <= finishA; startA++)
//        attach(terms[startA].coef, terms[startA].expon);
//    for (; startB <= finishB; startB++)
//        attach(terms[startB].coef, terms[startB].expon);
//    *finishD = avail - 1;
//}
//void main()
//{
//    float coefficient;
//    int exponent;
//    int startA, finishA, startB, finishB, n;
//    int startD, finishD;
//    printf("다항식 덧셈 프로그램\n");
//    printf("최고차항부터 순서대로 계수와 지수를 입력하시고, 계수에 0을 입력하면 해당 다항식의 입력은 종료됩니다.\n");
//
//    printf("\n다항식 A(x)\n\n");
//    startA = avail;
//    while (1)
//    {
//        printf("다항식 A(x)의 계수를 입력하세요. : ");
//        scanf_s("%f", &coefficient);
//        if (coefficient == 0)
//            break;
//        printf("다항식 A(x)의 지수를 입력하세요. : ");
//        scanf_s("%d", &exponent);
//        attach(coefficient, exponent);
//        printf("\n");
//    }
//    finishA = avail - 1;
//    printf("\n다항식 B(x)\n\n");
//    startB = avail;
//    while (1)
//    {
//        printf("다항식 B(x)의 계수를 입력하세요. : ");
//        scanf_s("%f", &coefficient);
//        if (coefficient == 0)
//            break;
//        printf("다항식 B(x)의 지수를 입력하세요. : ");
//        scanf_s("%d", &exponent);
//        attach(coefficient, exponent);
//        printf("\n");
//    }
//    finishB = avail - 1;
//    startD = avail;
//    finishD = avail;
//
//    printf("\nA(x) = ");
//    for (n = startA; n <= finishA; n++)
//    {
//        printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//        if (n != finishA)
//            printf("+ ");
//    }
//    printf("\nB(x) = ");
//    for (n = startB; n <= finishB; n++)
//    {
//        printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//        if (n != finishB)
//            printf("+ ");
//    }
//    padd(startA, finishA, startB, finishB, &startD, &finishD);
//    printf("\nD(x) = A(x) + B(x) = ");
//    for (n = startD; n <= finishD; n++)
//    {
//        printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
//        if (n != finishD)
//            printf("+ ");
//    }
//    printf("\n");
//}


//다항식 덧셈 리스트
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct PolyNode {
//    float coef;
//    int expon;
//    struct PolyNode* link;
//} PolyNode;
//
//PolyNode* createNode(float coef, int expon) {
//    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
//    if (!newNode) {
//        printf(stderr, "메모리 할당 오류\n");
//        exit(1);
//    }
//    newNode->coef = coef;
//    newNode->expon = expon;
//    newNode->link = NULL;
//    return newNode;
//}
//
//void insertTerm(PolyNode** poly, float coef, int expon) {
//    if (coef == 0) return;
//
//    PolyNode* newNode = createNode(coef, expon);
//    PolyNode* current = *poly, * prev = NULL;
//    while (current && current->expon > expon) {
//        prev = current;
//        current = current->link;
//    }
//
//    if (current && current->expon == expon) {
//        current->coef += coef;
//        if (current->coef == 0) {
//            if (prev)
//                prev->link = current->link;
//            else
//                *poly = current->link;
//            free(current);
//        }
//        free(newNode);
//    }
//    else {
//        newNode->link = current;
//        if (prev)
//            prev->link = newNode;
//        else
//            *poly = newNode;
//    }
//}
//
//PolyNode* addPoly(PolyNode* A, PolyNode* B) {
//    PolyNode* result = NULL;
//    while (A && B) {
//        if (A->expon > B->expon) {
//            insertTerm(&result, A->coef, A->expon);
//            A = A->link;
//        }
//        else if (A->expon < B->expon) {
//            insertTerm(&result, B->coef, B->expon);
//            B = B->link;
//        }
//        else {
//            insertTerm(&result, A->coef + B->coef, A->expon);
//            A = A->link;
//            B = B->link;
//        }
//    }
//
//    while (A) {
//        insertTerm(&result, A->coef, A->expon);
//        A = A->link;
//    }
//    while (B) {
//        insertTerm(&result, B->coef, B->expon);
//        B = B->link;
//    }
//    return result;
//}
//
//
//void printPoly(PolyNode* poly) {
//    if (!poly) {
//        printf("0\n");
//        return;
//    }
//
//    while (poly) {
//        printf("%.1fx^%d", poly->coef, poly->expon);
//        if (poly->link && poly->link->coef >= 0)
//            printf(" + ");
//        else if (poly->link)
//            printf(" ");
//        poly = poly->link;
//    }
//    printf("\n");
//}
//
//void freePoly(PolyNode* poly) {
//    while (poly) {
//        PolyNode* temp = poly;
//        poly = poly->link;
//        free(temp);
//    }
//}
//
//PolyNode* inputPoly(char name) {
//    float coef;
//    int expon;
//    PolyNode* poly = NULL;
//
//    printf("\n다항식 %c(x) 입력 (계수에 0 입력 시 종료):\n", name);
//    while (1) {
//        printf("계수: ");
//        scanf("%f", &coef);
//        if (coef == 0) break;
//        printf("지수: ");
//        scanf("%d", &expon);
//        insertTerm(&poly, coef, expon);
//    }
//    return poly;
//}
//
//int main() {
//    printf("연결 리스트 기반 다항식 덧셈 프로그램\n");
//
//    PolyNode* A = inputPoly('A');
//    PolyNode* B = inputPoly('B');
//
//    printf("\nA(x) = ");
//    printPoly(A);
//
//    printf("B(x) = ");
//    printPoly(B);
//
//    PolyNode* D = addPoly(A, B);
//
//    printf("A(x) + B(x) = ");
//    printPoly(D);
//
//    freePoly(A);
//    freePoly(B);
//    freePoly(D);
//
//    return 0;
//}
