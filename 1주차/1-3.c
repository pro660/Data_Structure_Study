// 3.1 배열을 이용하여 다항식 계산
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) ((x)<(y)? -1:((x)==(y))?0:1)
#define MAX_TERMS 100
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "다항식에 항이 너무 많다.");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}
void padd(int startA, int finishA, int startB, int finishB,
	int* startD, int* finishD)
{
	float coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].expon, terms[startB].expon))
		{
		case -1: attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;
}
int main(void)
{
	float a;
	int b, i;
	int starta, startb, startc, finisha, finishb, startd, finishd;
	starta = avail;
	while (1)
	{
		printf("다항식 A의 계수를 입력하시오. : ");
		scanf_s("%f", &a);
		if (a == 0)
			break;
		printf("다항식 A의 지수를 입력하시오. : ");
		scanf_s("%d", &b);
		attach(a, b);
	}
	finisha = avail - 1;
	startb = avail;
	while (1)
	{
		printf("다항식 B의 계수를 입력하시오. : ");
		scanf_s("%f", &a);
		if (a == 0)
			break;
		printf("다항식 B의 지수를 입력하시오. : ");
		scanf_s("%d", &b);
		attach(a, b);
	}
	finishb = avail - 1;
	padd(starta, finisha, startb, finishb, &startd, &finishd);
	printf("다항식 A : ");
	for (i = starta; i <= finisha; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finisha)
			printf(" + ");
	}
	printf("\n다항식 B : ");
	for (i = startb; i < finishb; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finishb)
			printf(" + ");
	}
	printf("\n다항식 D : ");
	for (i = startd; i <= finishd; i++)
	{
		printf("%fx^%d", terms[i].coef, terms[i].expon);
		if (i != finishd)
			printf(" + ");
	}
}

// 3.2 연결리스트를 이용하여 다항식 덧셈하기
#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
};
polyPointer a, b;
void attach(float coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}
polyPointer padd(polyPointer a, polyPointer b)
{
	polyPointer c, rear, temp;
	int sum;
	rear = (polyPointer)malloc(sizeof(*rear));
	c = rear;
	while (a && b)
	{
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link; b = b->link; break;
		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	return c;
}
void printPoly(polyPointer poly)
{
	while (poly)
	{
		printf("%dx^%d", poly->coef, poly->expon);
		if (poly->link)
			printf(" + ");
		poly = poly->link;
	}
	printf("\n");
}
int main(void)
{
	polyPointer rear;
	int j, k;
	rear = (polyPointer)malloc(sizeof(struct polyNode));
	a = rear;
	printf("다항식 A 입력\n");
	while (1)
	{
		printf("계수를 입력하시오. : ");
		scanf_s("%d", &k);
		if (k == 0) break;
		printf("지수를 입력하시오. : ");
		scanf_s("%d", &j);
		attach(k, j, &rear);
		if (j == 0) break;
	}
	rear->link = NULL;
	polyPointer temp = a; a = a->link; free(temp);
	rear = (polyPointer)malloc(sizeof(struct polyNode));
	b = rear;
	printf("다항식 B 입력\n");
	while (1)
	{
		printf("계수를 입력하시오. : ");
		scanf_s("%d", &k);
		if (k == 0) break;
		printf("지수를 입력하시오. : ");
		scanf_s("%d", &j);
		attach(k, j, &rear);
		if (j == 0) break;
	}
	rear->link = NULL;
	temp = b; b = b->link; free(temp);
	printf("다항식 A : ");
	printPoly(a);
	printf("다항식 B : ");
	printPoly(b);
	polyPointer result = padd(a, b);
	printf("다항식의 합 : ");
	printPoly(result);
}