/* 1. 희소행렬의 전치 (교재 프로그램 2.8) */

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 // 최대 항의 수 + 1
typedef struct
{
	int col; // 열
	int row; // 행
	int value; // 값
} term;
term a[MAX_TERMS];
term b[MAX_TERMS];
void transpose(term a[], term b[])
{	// a를 전치시켜 b를 생성
	int n, i, j, currentb;

	n = a[0].value; // 총 원소 수
	b[0].row = a[0].col; // b의 행 수 = a의 열 수
	b[0].col = a[0].row; // b의 열 수 = a의 행 수
	b[0].value = n;

	if (n > 0)
	{	// 0이 아닌 행렬 (원소가 하나라도 있는 행렬)
		currentb = 1;
		for (i = 0; i < a[0].col; i++) // a에서의 열별 전치
			for (j = 1; j <= n; j++) // 현재의 열로부터 원소를 찾는다.
				if (a[j].col == i)
				{	// 현재의 열에 있는 원소를 b에 첨가한다.
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
	}
}
int main()
{
	int i;

	printf("행의 개수: ");
	scanf_s("%d", &a[0].row);
	printf("열의 개수: ");
	scanf_s("%d", &a[0].col);
	printf("값의 개수: ");
	scanf_s("%d", &a[0].value);

	if (a[0].value >= MAX_TERMS)
	{
		fprintf(stderr, "값의 개수가 너무 큽니다.\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
		exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
	}
	else
		for (i = 1; i <= a[0].value; i++)
		{
			printf("\n행: ");
			scanf_s("%d", &a[i].row);
			printf("열: ");
			scanf_s("%d", &a[i].col);
			if (a[i].row >= a[0].row || a[i].col >= a[0].col)
			{
				fprintf(stderr, "입력한 행 또는 열이 %d * %d 보다 큽니다.\n", a[0].row, a[0].col);
				// Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
				exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
			}
			printf("값: ");
			scanf_s("%d", &a[i].value);
		}

	transpose(a, b);

	printf("\n\tA\t\t\t\t\tB\n");
	printf("\t행\t열\t값\t\t\t행\t열\t값\n");
	for (i = 0; i <= a[0].value; i++)
	{
		printf("a[%d]%6d%8d%8d\t\t", i, a[i].row, a[i].col, a[i].value);
		printf("b[%d]%6d%8d%8d\n", i, b[i].row, b[i].col, b[i].value);
	}
}
