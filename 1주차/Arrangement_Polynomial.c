/* 배열을 이용한 다항식의 덧셈 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100 // 배열 terms의 최대 크기
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1) // x, y 를 비교하는 삼항연산자 매크로 함수
typedef struct
{
	float coef; // 계수
	int expon; // 지수
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void attach(float coefficient, int exponent) // 계수와 지수를 전달.
{ // 새로운 항을 다항식에 첨가한다.
	if (avail >= MAX_TERMS)
	{
		fprintf(stderr, "다항식에 항이 너무 많다.\n");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent; // avail 위치에 넣고 avail을 하나 증가 시킴
}
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
	float coefficient;
	*startD = avail;

	while (startA <= finishA && startB <= finishB)
	{
		switch (COMPARE(terms[startA].expon, terms[startB].expon))
		{
		case -1: // A(x)의 expon이 B(x)의 expon보다 작은 경우
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0: // A(x)와 B(X)의 expon이 같은 경우
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient) // coef가 0이 되는 경우 제외
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1: // A(x)의 expon이 B(x)의 expon보다 큰 경우
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}

	for (; startA <= finishA; startA++) // A(x)의 나머지 항들을 첨가한다.
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1; // avail의 마지막 index를 저장
}
void main()
{
	float coefficient;
	int exponent;
	int startA, finishA, startB, finishB, n;
	int startD, finishD;
	printf("다항식 덧셈 프로그램\n");
	printf("최고차항부터 순서대로 계수와 지수를 입력하시고, 계수에 0을 입력하면 해당 다항식의 입력은 종료됩니다.\n");

	printf("\n다항식 A(x)\n\n");
	startA = avail;
	while (1) // 다항식 A(x) 입력
	{
		printf("다항식 A(x)의 계수를 입력하세요. : ");
		scanf_s("%f", &coefficient);
		if (coefficient == 0)
			break;
		printf("다항식 A(x)의 지수를 입력하세요. : ");
		scanf_s("%d", &exponent);
		attach(coefficient, exponent);
		printf("\n");
	}
	finishA = avail - 1;
	printf("\n다항식 B(x)\n\n");
	startB = avail;
	while (1) // 다항식 B(x) 입력
	{
		printf("다항식 B(x)의 계수를 입력하세요. : ");
		scanf_s("%f", &coefficient);
		if (coefficient == 0)
			break;
		printf("다항식 B(x)의 지수를 입력하세요. : ");
		scanf_s("%d", &exponent);
		attach(coefficient, exponent);
		printf("\n");
	}
	finishB = avail - 1;
	startD = avail;
	finishD = avail;

	printf("\nA(x) = "); // 다항식 A(x) 출력
	for (n = startA; n <= finishA; n++)
	{
		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
		if (n != finishA)
			printf("+ ");
	}
	printf("\nB(x) = "); // 다항식 B(x) 출력
	for (n = startB; n <= finishB; n++)
	{
		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
		if (n != finishB)
			printf("+ ");
	}
	padd(startA, finishA, startB, finishB, &startD, &finishD);
	printf("\nD(x) = A(x) + B(x) = ");
	for (n = startD; n <= finishD; n++)
	{
		printf("%.1fx^%d ", terms[n].coef, terms[n].expon);
		if (n != finishD)
			printf("+ ");
	}
	printf("\n");
}
