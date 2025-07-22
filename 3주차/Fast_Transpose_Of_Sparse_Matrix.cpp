/* 2. 희소행렬의 빠른 전치 (교재 프로그램 2.9) */

#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 // 최대 항의 수 + 1
#define MAX_COL 101
typedef struct
{
	int col; // 열
	int row; // 행
	int value; // 값
} term;
term a[MAX_TERMS];
term b[MAX_TERMS];
void fastTranspose(term a[], term b[])
{	// a를 전치시켜 b에 저장.
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; b[0].col = a[0].row;
	b[0].value = numTerms;
	if (numTerms > 0)
	{	// 0이 아닌 행렬
		for (i = 0; i < numCols; i++) // rowTerms 배열을 0으로 초기화.
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++) // 값이 있는 열을 index로 배열에 값이 있다고 표시.
			rowTerms[a[i].col]++;
		// rowTerms에 대한 값 계산.
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		/*
		startingPos 계산.
		rowTerms[i - 1]: 행 i - 1 에 있는 원소의 수
		startingPos[i - 1]: 행 i - 1 의 시작 위치
		*/
		for (i = 1; i <= numTerms; i++)
		{	// 3원소 쌍을 전치 행렬에 저장.
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;
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

	fastTranspose(a, b);

	printf("\n\tA\t\t\t\t\tB\n");
	printf("\t행\t열\t값\t\t\t행\t열\t값\n");
	for (i = 0; i <= a[0].value; i++)
	{
		printf("a[%d]%6d%8d%8d\t\t", i, a[i].row, a[i].col, a[i].value);
		printf("b[%d]%6d%8d%8d\n", i, b[i].row, b[i].col, b[i].value);
	}
}