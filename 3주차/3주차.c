/*
1. 희소행렬의 전치 (교재 프로그램 2.8)
2. 희소행렬의 빠른 전치 (교재 프로그램 2.9)
3. 1, 2번 알고리즘의 시간복잡도를 계산해보기
4. 교재 그림 5.16의 이진트리를 연결 표현으로 구성한 다음
중위순회(프로그램 5.1), 전위순회(프로그램 5.2), 후위순회(프로그램 5.3) 구현하기
*/

/* 1. 희소행렬의 전치 (교재 프로그램 2.8) */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101 // 최대 항의 수 + 1
//typedef struct
//{
//	int col; // 열
//	int row; // 행
//	int value; // 값
//} term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void transpose(term a[], term b[])
//{	// a를 전치시켜 b를 생성
//	int n, i, j, currentb;
//
//	n = a[0].value; // 총 원소 수
//	b[0].row = a[0].col; // b의 행 수 = a의 열 수
//	b[0].col = a[0].row; // b의 열 수 = a의 행 수
//	b[0].value = n;
//
//	if (n > 0)
//	{	// 0이 아닌 행렬 (원소가 하나라도 있는 행렬)
//		currentb = 1;
//		for (i = 0; i < a[0].col; i++) // a에서의 열별 전치
//			for (j = 1; j <= n; j++) // 현재의 열로부터 원소를 찾는다.
//				if (a[j].col == i)
//				{	// 현재의 열에 있는 원소를 b에 첨가한다.
//					b[currentb].row = a[j].col;
//					b[currentb].col = a[j].row;
//					b[currentb].value = a[j].value;
//					currentb++;
//				}
//	}
//}
//int main()
//{
//	int i;
//
//	printf("행의 개수: ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수: ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수: ");
//	scanf_s("%d", &a[0].value);
//
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//		exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	}
//	else
//		for (i = 1; i <= a[0].value; i++)
//		{
//			printf("\n행: ");
//			scanf_s("%d", &a[i].row);
//			printf("열: ");
//			scanf_s("%d", &a[i].col);
//			if (a[i].row >= a[0].row || a[i].col >= a[0].col)
//			{
//				fprintf(stderr, "입력한 행 또는 열이 %d * %d 보다 큽니다.\n", a[0].row, a[0].col);
//				// Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//				exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//			}
//			printf("값: ");
//			scanf_s("%d", &a[i].value);
//		}
//
//	transpose(a, b);
//
//	printf("\n\tA\t\t\t\t\tB\n");
//	printf("\t행\t열\t값\t\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]%6d%8d%8d\t\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]%6d%8d%8d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}

/* 2. 희소행렬의 빠른 전치 (교재 프로그램 2.9) */

//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101 // 최대 항의 수 + 1
//#define MAX_COL 101
//typedef struct
//{
//	int col; // 열
//	int row; // 행
//	int value; // 값
//} term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void fastTranspose(term a[], term b[])
//{	// a를 전치시켜 b에 저장.
//	int rowTerms[MAX_COL], startingPos[MAX_COL];
//	int i, j, numCols = a[0].col, numTerms = a[0].value;
//	b[0].row = numCols; b[0].col = a[0].row;
//	b[0].value = numTerms;
//	if (numTerms > 0)
//	{	// 0이 아닌 행렬
//		for (i = 0; i < numCols; i++) // rowTerms 배열을 0으로 초기화.
//			rowTerms[i] = 0;
//		for (i = 1; i <= numTerms; i++) // 값이 있는 행을 index로 배열에 값이 있다고 표시.
//			rowTerms[a[i].col]++;
//		// rowTerms에 대한 값 계산.
//		startingPos[0] = 1;
//		for (i = 1; i < numCols; i++)
//			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
//		/*
//		startingPos 계산.
//		rowTerms[i - 1]: 행 i - 1 에 있는 원소의 수
//		startingPos[i - 1]: 행 i - 1 의 시작 위치
//		*/
//		for (i = 1; i <= numTerms; i++)
//		{	// 3원소 쌍을 전치 행렬에 저장.
//			j = startingPos[a[i].col]++;
//			b[j].row = a[i].col; b[j].col = a[i].row;
//			b[j].value = a[i].value;
//		}
//	}
//}
//int main()
//{
//	int i;
//
//	printf("행의 개수: ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수: ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수: ");
//	scanf_s("%d", &a[0].value);
//
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n"); // Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//		exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//	}
//	else
//		for (i = 1; i <= a[0].value; i++)
//		{
//			printf("\n행: ");
//			scanf_s("%d", &a[i].row);
//			printf("열: ");
//			scanf_s("%d", &a[i].col);
//			if (a[i].row >= a[0].row || a[i].col >= a[0].col)
//			{
//				fprintf(stderr, "입력한 행 또는 열이 %d * %d 보다 큽니다.\n", a[0].row, a[0].col);
//				// Standard Error: 에러 메세지를 출력할 장치 (버퍼없이 바로 출력 가능)
//				exit(EXIT_FAILURE); // exit(1): 에러 메세지 종료 -> 프로그램, 프로세서 종료
//			}
//			printf("값: ");
//			scanf_s("%d", &a[i].value);
//		}
//
//	fastTranspose(a, b);
//
//	printf("\n\tA\t\t\t\t\tB\n");
//	printf("\t행\t열\t값\t\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]%6d%8d%8d\t\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]%6d%8d%8d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}

/* 4. 교재 그림 5.16의 이진트리를 연결 표현으로 구성한 다음
중위순회(프로그램 5.1), 전위순회(프로그램 5.2), 후위순회(프로그램 5.3) 구현하기 */

//#include <stdio.h>
//#include <stdlib.h>
//#define MALLOC(p, s)\
// if (! ((p) = (treePointer)malloc(s))) {\
//fprintf(stderr, "insufficient memory");\
//exit(EXIT_FAILURE);\
//}
//typedef struct node* treePointer;
//typedef struct node {
//	char data;
//	treePointer leftChild, rightChild;
//};
//void mallocRightChild(treePointer first, char data)
//{	// 트리의 오른쪽 자식 생성.
//	treePointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->rightChild = NULL;
//	temp->data = data;
//	temp->leftChild = NULL;
//	first->rightChild = temp;
//}
//treePointer mallocLeftChild(treePointer first, char data)
//{	// 트리의 왼쪽 자식 생성.
//	treePointer temp;
//	MALLOC(temp, sizeof(*temp));
//	temp->rightChild = NULL;
//	temp->data = data;
//	temp->leftChild = NULL;
//	first->leftChild = temp;
//	return first->leftChild;
//}
//void arithmeticTree(treePointer root)
//{	// (P. 221) 그림 5.16 이진트리 구현.
//	treePointer Child;
//
//	root->data = '+';
//	mallocRightChild(root, 'E');
//	Child = mallocLeftChild(root, '*');
//	mallocRightChild(Child, 'D');
//	Child = mallocLeftChild(Child, '*');
//	mallocRightChild(Child, 'C');
//	Child = mallocLeftChild(Child, '/');
//	mallocRightChild(Child, 'B');
//	Child = mallocLeftChild(Child, 'A');
//}
//void inorder(treePointer ptr)
//{	// 중위 트리 순회
//	if (ptr)
//	{
//		inorder(ptr->leftChild);
//		printf("%c", ptr->data);
//		inorder(ptr->rightChild);
//	}
//}
//void preorder(treePointer ptr)
//{	// 전위 트리 순회
//	if (ptr)
//	{
//		printf("%c", ptr->data);
//		preorder(ptr->leftChild);
//		preorder(ptr->rightChild);
//	}
//}
//void postorder(treePointer ptr)
//{	// 후위 트리 순회
//	if (ptr)
//	{
//		postorder(ptr->leftChild);
//		postorder(ptr->rightChild);
//		printf("%c", ptr->data);
//	}
//}
//int main()
//{
//	treePointer root;
//	MALLOC(root, sizeof(*root));
//	arithmeticTree(root);
//	printf("중위 순회: ");
//	inorder(root);
//	printf("\n전위 순회: ");
//	preorder(root);
//	printf("\n후위 순회: ");
//	postorder(root);
//	printf("\n");
//}
