/* 행렬 전치 연산 횟수 측정 버전 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101 

typedef struct {
    int col;
    int row;
    int value;
} term;

// 전역 연산 카운터
long long opCount = 0;

// 함수 선언
void transpose(term a[], term b[]);
void matrix_Input(term a[]);
void matrix_Output(term trans_a[]);

// 101 크기의 구조체 배열 선언
term a[MAX_TERMS];
term trans_a[MAX_TERMS];

int main(void) {
    matrix_Input(a);
    transpose(a, trans_a);
    matrix_Output(trans_a);
    printf("Operation count (proxy for time complexity): %lld\n", opCount);
    return 0;
}

void matrix_Input(term a[]) {
    int i;
    printf("Enter the size of matrix and count of non-zero values:\nRow Column Value\n");
    scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    opCount += 3;  // scanf 3회

    // 유효값 개수 검증
    if (a[0].row * a[0].col < a[0].value) {
        opCount += 2;  // 곱셈 1회, 비교 1회
        fprintf(stderr, "The number of values exceeds the size of the matrix.\n");
        exit(1);
    }
    opCount += 1;  // 비교 실패 시에도 1회

    printf("Enter each non-zero term (Row Column Value):\n");
    for (i = 1; i <= a[0].value; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
        opCount += 3;  // scanf 3회
    }
    opCount += a[0].value;  // for 루프 비교 및 증분
}

void matrix_Output(term trans_a[]) {
    int i;
    printf("\nTransposed sparse matrix terms:\n");
    for (i = 1; i <= trans_a[0].value; i++) {
        printf("Row: %d, Column: %d, Value: %d\n",
               trans_a[i].row, trans_a[i].col, trans_a[i].value);
        opCount += 3;  // printf 인자 처리
    }
    opCount += trans_a[0].value;  // for 루프 비교 및 증분
}

void transpose(term a[], term b[]) {
    int n = a[0].value;
    opCount += 1;  // 대입 1회

    // 헤더 정보 설정
    b[0].row   = a[0].col;
    b[0].col   = a[0].row;
    b[0].value = n;
    opCount += 3;  // 대입 3회

    if (n > 0) {
        int currentb = 1;
        opCount += 1;  // 대입 1회

        // 각 열에 대해 a를 순회
        for (int i = 0; i < a[0].col; i++) {
            opCount += 1;  // for 비교/증가
            for (int j = 1; j <= n; j++) {
                opCount += 2;  // for 비교/증가
                opCount += 1;  // a[j].col 참조
                if (a[j].col == i) {
                    opCount += 1;  // 비교 성공 시
                    // 전치 항 추가
                    b[currentb].row   = a[j].col;
                    b[currentb].col   = a[j].row;
                    b[currentb].value = a[j].value;
                    opCount += 3;  // 대입 3회

                    currentb++;
                    opCount += 1;  // 증분 1회
                }
            }
        }
        opCount += a[0].col;  // 외부 for 루프 종료 비교
        opCount += n;         // 내부 for 루프 총 종료 비교 수
    }
    opCount += 1;  // if 조건 검사
}
//////////////////////////////////////////////////////////////////
/* 행렬의 빠른 전치 — 연산 횟수 계측 버전 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101 

typedef struct {
    int col;
    int row;
    int value;
} term;

// 전역 연산 카운터
long long opCount = 0;

// 함수 선언
void fastTranspose(term a[], term b[]);
void matrix_Input(term a[]);
void matrix_Output(term trans_a[]);

// 101의 크기를 가지는 구조체 배열 선언
term a[MAX_TERMS];
term trans_a[MAX_TERMS];

int main(){
    matrix_Input(a);

    fastTranspose(a, trans_a);

    matrix_Output(trans_a);

    printf("\nOperation count (≈ time complexity proxy): %lld\n", opCount);
    return 0;
}

void matrix_Input(term a[]){
    int i;
    printf("Enter the size of matrix, count of numbers:\nRow Column Value\n");
    scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
    opCount += 3;  // scanf 3개

    if (a[0].row * a[0].col < a[0].value) {
        fprintf(stderr, "The number of values exceeds the size of the matrix.\n");
        exit(1);
    }
    opCount += 2;  // 곱셈 1회, 비교 1회

    printf("Enter the location of value and the value:\nRow Column Value\n");
    for (i = 1; i <= a[0].value; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
        opCount += 3; // scanf 3개
    }
    opCount += a[0].value; // for 루프 비교·증가
}

void matrix_Output(term trans_a[]){
    int i;
    printf("\nfastTransposed matrix:\n");
    for (i = 1; i <= trans_a[0].value; i++) {
        printf("Row: %d, Column: %d, Value: %d\n",
               trans_a[i].row, trans_a[i].col, trans_a[i].value);
        opCount += 3; // printf 인자 처리 (대략)
    }
    opCount += trans_a[0].value; // for 루프 비교·증가
}

void fastTranspose(term a[], term b[]){
    int rowTerms[MAX_TERMS], startingPos[MAX_TERMS];
    int i, j, numCols = a[0].col, numTerms = a[0].value;

    // 헤더 정보 대입
    b[0].row   = numCols;  b[0].col   = a[0].row;
    b[0].value = numTerms;
    opCount += 3;  // 대입 3번

    if (numTerms > 0) {
        // 1) 열별 용어 개수 초기화
        for (i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
            opCount += 2;  // 대입 1, 루프 비교/증가 1
        }

        // 2) 각 열에 속한 항 개수 세기
        for (i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
            opCount += 3;  // a[i].col 참조 1, 증가 1, 루프 관리 1
        }

        // 3) 시작 위치 계산
        startingPos[0] = 1;
        opCount += 1;  // 대입
        for (i = 1; i < numCols; i++) {
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
            opCount += 4;  // 참조 2, 덧셈 1, 대입 1
        }

        // 4) 실제 전치
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row   = a[i].col;
            b[j].col   = a[i].row;
            b[j].value = a[i].value;
            opCount += 6;  // a[i].col 참조 1, 증가 1, 대입 3, 루프 관리 1
        }
    }
}
