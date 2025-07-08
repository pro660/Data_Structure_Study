/* 연결리스트를 이용한 다항식의 덧셈 */

#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x, y) (((x) < (y)) ? -1: ((x) == (y)) ? 0: 1) // x, y 를 비교하는 삼항연산자 매크로 함수
#define MALLOC(p, s)\
 if (! ((p) = (polyPointer)malloc(s))) {\
fprintf(stderr, "insufficient memory");\
exit(EXIT_FAILURE);\
}
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
} polyNode;
polyPointer a, b;
void attach(int coefficient, int exponent, polyPointer* ptr)
{ // coef = coefficient이고 expon = exponent인 새로운 노드를 생성하고, 그것을 ptr에 의해 참조되는 노드에 첨가한다. ptr을 갱신하여 이 새로운 노드를 참조하도록 한다.
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}
polyPointer padd(polyPointer a, polyPointer b)
{ // a와 b가 합산된 다항식을 반환
	polyPointer c, rear, temp;
	int sum;
	MALLOC(rear, sizeof(*rear));
	c = rear;
	while (a && b)
		switch (COMPARE(a->expon, b->expon))
		{
		case -1: // a->expon < b->expon
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0: // a->expon = b->expon
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link;
			b = b->link;
			break;
		case 1: // a->expon > b->expon
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	// 리스트 a와 리스트 b의 나머지를 복사
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	// 필요 없는 초기 노드를 삭제
	temp = c;
	c = c->link;
	free(temp);
	return c;
}
void printPoly(polyPointer first)
{
	for (; first; first = first->link)
	{
		if (first->link) // NULL 값이 나오면 다음 항이 없음
		{
			if (first->coef < 0) // 계수가 0보다 작을 때
				printf("(%dx^%d) + ", first->coef, first->expon);
			else
				printf("%dx^%d + ", first->coef, first->expon);
		}
		else
		{
			if (first->coef < 0) // 계수가 0보다 작을 때
				printf("(%dx^%d)", first->coef, first->expon);
			else
				printf("%dx^%d", first->coef, first->expon);
		}
	}
	printf("\n");
}
int main()
{
	polyPointer rearA, rearB, temp, c;

	// 다항식 a 생성: 3x^14 + 2x^8 + 1
	MALLOC(a, sizeof(*a));
	rearA = a;
	attach(3, 14, &rearA);
	attach(2, 8, &rearA);
	attach(1, 0, &rearA);
	rearA->link = NULL;
	temp = a; a = a->link; free(temp); // 헤더 제거

	// 다항식 b 생성: 8x^14 -3x^10 + 10x^6
	MALLOC(b, sizeof(*b));
	rearB = b;
	attach(8, 14, &rearB);
	attach(-3, 10, &rearB);
	attach(10, 6, &rearB);
	rearB->link = NULL;
	temp = b; b = b->link; free(temp); // 헤더 제거

	// 출력: a, b
	printf("Polynomial A(x) = ");
	printPoly(a);
	printf("Polynomial B(x) = ");
	printPoly(b);

	// 덧셈 결과
	c = padd(a, b);
	printf("Polynomial A(x) + B(x) = ");
	printPoly(c);
}
