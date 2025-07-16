// 2. 희소행렬의 빠른 전치 ( 교재 프로그램 2.9 )
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
#define MAX_COL 101
typedef struct
{
	int col;
	int row;
	int value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];
void fastTranspose(term a[],term b[])
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; b[0].col = a[0].row;
	b[0].value = numTerms;
	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
int main(void)
{
	int i;
	printf("행의 개수 : ");
	scanf_s("%d", &a[0].row);
	printf("열의 개수 : ");
	scanf_s("%d", &a[0].col);
	printf("값의 개수 : ");
	scanf_s("%d", &a[0].value);
	if (a[0].value >= MAX_TERMS)
	{
		fprintf(stderr, "값의 개수가 너무 큽니다.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		for (i = 1; i <= a[0].value; i++)
		{
			printf("\n행 : ");
			scanf_s("%d", &a[i].row);
			printf("열 : ");
			scanf_s("%d", &a[i].col);
			if (a[i].row >= a[0].row
				|| a[i].col >= a[0].col)
			{
				fprintf(stderr, "입력한 행 또는 열이 \
			%d * %d 보다 큽니다.\n", a[0].row, a[0].col);
				exit(EXIT_FAILURE);
			}
			printf("값 : ");
			scanf_s("%d", &a[i].value);
		}
	}
	fastTranspose(a, b);
	printf("\n\tA\t\t\tB\n");
	printf("\t행\t열\t값\t\t행\t열\t값\n");
	for (i = 0; i <= a[0].value; i++)
	{
		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
	}
}