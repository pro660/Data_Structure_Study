// 1. 희소행렬의 전치 (교재 프로그램 2.8)
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct
{
	int col;
	int row;
	int value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];
void transpose(term a[], term b[])
{
	int n, i, j, currentb;
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;
	if (n > 0)
	{
		currentb = 1;
		for (i = 0; i < a[0].col; i++)
			for (j = 1; j <= n; j++)
				if (a[j].col == i)
				{
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
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
	transpose(a, b);
	printf("\n\tA\t\t\tB\n");
	printf("\t행\t열\t값\t\t행\t열\t값\n");
	for (i = 0; i <= a[0].value; i++)
	{
		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
	}
}