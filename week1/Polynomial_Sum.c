#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y)((x)<(y)?-1:(x)>(y)?1:0)
#define MAX_TERMS 100

void padd(int ,int, int, int, int *,int *);
void attach(int , int);
void prn_Poly(int, int);
void input_Poly(int );

//다항식의 구조 선언(계수와 지수)
typedef struct{
    int coef;
    int expon;
} polynomial;
polynomial terms[MAX_TERMS]; //구조체 배열 terms 선언
int avail = 0;

int main(){
    int startA = avail, startB, finishA, finishB;
    int startD, finishD, sizeA, sizeB;

    printf("Enter the number of terms in polynomial A: "); //다항식 a의 항의 개수
    scanf("%d",&sizeA);
    input_Poly(sizeA);

    finishA = avail - 1;
    startB = avail; 

    printf("\nEnter the number of terms in polynomial B: "); //다항식 b의 항의 개수
    scanf("%d",&sizeB);
    input_Poly(sizeB);

    finishB = avail - 1;

    padd(startA, finishA, startB, finishB, &startD, &finishD);
    prn_Poly(startD, finishD);

    return 0;
}

//input_poly를 통해 넣었던 값을 attach를 통해 finishB 위치 뒤에 삽입
void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD){ 
    int coefficient;
    *startD = avail;

    while(startA <= finishA && startB <= finishB) 
        switch (COMPARE(terms[startA].expon, terms[startB].expon)) //지수를 비교하여 지수가 큰 것부터 삽입, 같으면 계수를 더함
        {
        case -1:
            attach(terms[startB].coef, terms[startB].expon);
            startB++;
            break;
        case 0:
            coefficient = terms[startA].coef + terms[startB].coef;
            if(coefficient) //계수의 합이 0인것을 고려
                attach(coefficient, terms[startA].expon);
            startA++;
            startB++;
            break;
        case 1:
            attach(terms[startA].coef, terms[startA].expon);
            startA++;
        }

        for(; startA <= finishA; startA++) //남은 항들을 모두 attach
            attach(terms[startA].coef, terms[startA].expon);
        for(; startB <= finishB; startB++)
            attach(terms[startB].coef, terms[startB].expon);

        *finishD = avail-1; //avail을 더하다보면 마지막 항의 위치+1을 인덱스로 가지므로 -1을 적용
}
void attach(int coefficient, int exponent){
    if(avail >= MAX_TERMS){
        fprintf(stderr, "다항식의 항이 너무 많습니다.");
        exit(1);
    }

    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}
void input_Poly(int size){ //다항식을 계수와 지수로 나누어 차례대로 terms에 삽입
    for(int i=0; i<size; i++){
        printf("Enter the coefficient for the term : ");
        scanf("%d",&terms[avail].coef);
        printf("Enter the exponent for the term : ");
        scanf("%d",&terms[avail].expon);
        avail++;
    }
}
void prn_Poly(int startD, int finishD){ //덧셈이 완료된 최종다항식을 출력하는 형식
    for (int i = startD; i <= finishD; i++) {
        if(terms[i].expon != 0)
            printf("%dx^%d", terms[i].coef, terms[i].expon);
        else    
            printf("%d", terms[i].coef);
        if (i < finishD && terms[i+1].coef >= 0)
            printf(" + ");
    }
    printf("\n");
}
