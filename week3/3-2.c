/* 행렬의 빠른 전치 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 

typedef struct 
{
	int col;
	int row;
	int value;
} term; //행,열,값을 표현하기 위해 하나의 term이라는 자료형을 생성

//함수 선언
void fastTranspose(term a[],term b[]);
void matrix_Input(term a[]);
void matrix_Output(term trans_a[]);

//101의 크기를 가지는 구조체 배열 선언
term a[MAX_TERMS];
term trans_a[MAX_TERMS];

int main(){
	matrix_Input(a);
    fastTranspose(a,trans_a);
	matrix_Output(trans_a);

	return 0;
}

void matrix_Input(term a[]){ //입력받는 함수
	
	int i;
	
	printf("Enter the size of matrix, count of numbers: \nRow Column Value\n");
	scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value); //전치행렬 알고리즘에서 0인덱스에는 행렬의 size와 유효한 값의 개수를 입력
	
	if(a[0].row * a[0].col < a[0].value){ // 값의 개수가 행렬의 크기보다 클 때 오류
		fprintf(stderr, "The number of values exceeds the size of the matrix.");
		exit(1); 
	}

	printf("Enter the location of value and the value: \nRow Column Value\n");
	for(i=1; i<=a[0].value; i++){ // 몇 번 행,열에 어떠한 값이 있는지 입력받음
		scanf("%d %d %d",&a[i].row ,&a[i].col ,&a[i].value );
	}
}

void matrix_Output(term trans_a[]){ //출력하는 함수
	
	int i;
	
	printf("\nfastTransposed matrix:\n");
	for(i = 1; i <= trans_a[0].value; i++) { // 유효한 값에 대한 행과 열, 그 위치에 대한 값만 출력
		printf("Row: %d, Column: %d, Value: %d\n", trans_a[i].row, trans_a[i].col, trans_a[i].value);
	}
}

void fastTranspose (term a[], term b[]){ //행렬의 빠른 전치 알고리즘

    int rowTerms[MAX_TERMS], startingPos[MAX_TERMS];
    int i, j, numCols = a[0].col, numTerms = a[0].value;

	b[0].row = numCols; //행과 열을 서로 뒤바꿈
	b[0].col = a[0].row; 
    b[0].value = numTerms;

    if (numTerms>0) { //유효한 값이 1개 이상 있다면 실행
	    for(i=0;  i<numCols; i++) 
            rowTerms[i] = 0; 
        for(i=1; i<=numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for(i=1; i<numCols; i++)
            startingPos[i] = startingPos[i-1]+rowTerms[i-1];
        for(i=1; i<=numTerms; i++){
            j=startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
	}
}