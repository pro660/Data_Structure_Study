////1.희소 행렬의 전치
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//typedef struct
//{
//	int col;
//	int row;
//	int value;
//}term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void transpose(term a[], term b[])
//{
//	int n, i, j, currentb;
//	n = a[0].value;
//	b[0].row = a[0].col;
//	b[0].col = a[0].row;
//	b[0].value = n;
//	if (n > 0)
//	{
//		currentb = 1;
//		for (i = 0; i < a[0].col; i++)
//			for (j = 1; j <= n; j++)
//				if (a[j].col == i)
//				{
//					b[currentb].row = a[j].col;
//					b[currentb].col = a[j].row;
//					b[currentb].value = a[j].value;
//					currentb++;
//				}
//	}
//}
//int main(void)
//{
//	int i;
//	printf("행의 개수 : ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수 : ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수 : ");
//	scanf_s("%d", &a[0].value);
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n");
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		for (i = 1; i <= a[0].value; i++)
//		{
//			printf("\n행 : ");
//			scanf_s("%d", &a[i].row);
//			printf("열 : ");
//			scanf_s("%d", &a[i].col);
//			if (a[i].row >= a[0].row
//				|| a[i].col >= a[0].col)
//			{
//				fprintf(stderr, "입력한 행 또는 열이 \
//			%d * %d 보다 큽니다.\n", a[0].row, a[0].col);
//				exit(EXIT_FAILURE);
//			}
//			printf("값 : ");
//			scanf_s("%d", &a[i].value);
//		}
//	}
//	transpose(a, b);
//	printf("\n\tA\t\t\tB\n");
//	printf("\t행\t열\t값\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}
//
//// 2.희소 행렬의 빠른 전치
//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//#define MAX_COL 101
//typedef struct
//{
//	int col;
//	int row;
//	int value;
//}term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void fastTranspose(term a[], term b[])
//{
//	int rowTerms[MAX_COL], startingPos[MAX_COL];
//	int i, j, numCols = a[0].col, numTerms = a[0].value;
//	b[0].row = numCols; b[0].col = a[0].row;
//	b[0].value = numTerms;
//	if (numTerms > 0)
//	{
//		for (i = 0; i < numCols; i++)
//			rowTerms[i] = 0;
//		for (i = 1; i <= numTerms; i++)
//			rowTerms[a[i].col]++;
//		startingPos[0] = 1;
//		for (i = 1; i < numCols; i++)
//			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
//		for (i = 1; i <= numTerms; i++)
//		{
//			j = startingPos[a[i].col]++;
//			b[j].row = a[i].col; b[j].col = a[i].row;
//			b[j].value = a[i].value;
//		}
//	}
//}
//int main(void)
//{
//	int i;
//	printf("행의 개수 : ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수 : ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수 : ");
//	scanf_s("%d", &a[0].value);
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n");
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		for (i = 1; i <= a[0].value; i++)
//		{
//			printf("\n행 : ");
//			scanf_s("%d", &a[i].row);
//			printf("열 : ");
//			scanf_s("%d", &a[i].col);
//			if (a[i].row >= a[0].row
//				|| a[i].col >= a[0].col)
//			{
//				fprintf(stderr, "입력한 행 또는 열이 \
//			%d * %d 보다 큽니다.\n", a[0].row, a[0].col);
//				exit(EXIT_FAILURE);
//			}
//			printf("값 : ");
//			scanf_s("%d", &a[i].value);
//		}
//	}
//	fastTranspose(a, b);
//	printf("\n\tA\t\t\tB\n");
//	printf("\t행\t열\t값\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}
//
//// 3. 1,2번 알고리즘의 시간복잡도계산 해보기
//// 3-1 희소행렬 전치 시간복잡도 계산
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//typedef struct {
//	int col;
//	int row;
//	int value;
//} term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void transpose(term a[], term b[])
//{
//	int n, i, j, currentb;
//	int count = 0;
//	n = a[0].value;
//	b[0].row = a[0].col;
//	b[0].col = a[0].row;
//	b[0].value = n;
//	if (n > 0) {
//		currentb = 1;
//		for (i = 0; i < a[0].col; i++) {
//			for (j = 1; j <= n; j++) {
//				count++;
//				if (a[j].col == i) {
//					b[currentb].row = a[j].col;
//					b[currentb].col = a[j].row;
//					b[currentb].value = a[j].value;
//					currentb++;
//				}
//			}
//		}
//	}
//	printf("\nO(n) : %d ( %d x %d ) \n",
//		count, a[0].col, a[0].value);
//}
//int main(void)
//{
//	int i;
//	printf("행의 개수 : ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수 : ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수 : ");
//	scanf_s("%d", &a[0].value);
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n");
//		exit(EXIT_FAILURE);
//	}
//	for (i = 1; i <= a[0].value; i++)
//	{
//		printf("\n행 : ");
//		scanf_s("%d", &a[i].row);
//		printf("열 : ");
//		scanf_s("%d", &a[i].col);
//		if (a[i].row >= a[0].row || a[i].col >= a[0].col) {
//			fprintf(stderr, "입력한 행 또는 열이 %d * %d 보다 큽니다.\n",
//				a[0].row, a[0].col);
//			exit(EXIT_FAILURE);
//		}
//		printf("값 : ");
//		scanf_s("%d", &a[i].value);
//	}
//	transpose(a, b);
//	printf("\n\tA\t\t\tB\n");
//	printf("\t행\t열\t값\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}
//
//// 3-2 희소행렬 빠른 전치 시간복잡도 계산
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_TERMS 101
//#define MAX_COL 101
//typedef struct {
//	int col;
//	int row;
//	int value;
//} term;
//term a[MAX_TERMS];
//term b[MAX_TERMS];
//void fastTranspose(term a[], term b[])
//{
//	int rowTerms[MAX_COL], startingPos[MAX_COL];
//	int i, j;
//	int numCols = a[0].col;
//	int numTerms = a[0].value;
//	int count = 0;
//	b[0].row = numCols;
//	b[0].col = a[0].row;
//	b[0].value = numTerms;
//	if (numTerms > 0)
//	{
//		for (i = 0; i < numCols; i++)
//		{
//			rowTerms[i] = 0;
//			count++;
//		}
//		for (i = 1; i <= numTerms; i++)
//		{
//			rowTerms[a[i].col]++;
//			count++;
//		}
//		startingPos[0] = 1;
//		for (i = 1; i < numCols; i++)
//		{
//			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
//			count++;
//		}
//		for (i = 1; i <= numTerms; i++) {
//			j = startingPos[a[i].col]++;
//			b[j].row = a[i].col;
//			b[j].col = a[i].row;
//			b[j].value = a[i].value;
//			count += 4;
//		}
//	}
//	printf("\nO(n) : %d\n", count);
//}
//int main(void)
//{
//	int i;
//	printf("행의 개수 : ");
//	scanf_s("%d", &a[0].row);
//	printf("열의 개수 : ");
//	scanf_s("%d", &a[0].col);
//	printf("값의 개수 : ");
//	scanf_s("%d", &a[0].value);
//	if (a[0].value >= MAX_TERMS)
//	{
//		fprintf(stderr, "값의 개수가 너무 큽니다.\n");
//		exit(EXIT_FAILURE);
//	}
//	for (i = 1; i <= a[0].value; i++)
//	{
//		printf("\n행 : ");
//		scanf_s("%d", &a[i].row);
//		printf("열 : ");
//		scanf_s("%d", &a[i].col);
//		if (a[i].row >= a[0].row || a[i].col >= a[0].col)
//		{
//			fprintf(stderr, "입력한 행 또는 열이 %d * %d 보다 큽니다.\n", a[0].row, a[0].col);
//			exit(EXIT_FAILURE);
//		}
//		printf("값 : ");
//		scanf_s("%d", &a[i].value);
//	}
//	fastTranspose(a, b);
//	printf("\n\tA\t\t\tB\n");
//	printf("\t행\t열\t값\t\t행\t열\t값\n");
//	for (i = 0; i <= a[0].value; i++)
//	{
//		printf("a[%d]\t%2d\t%2d\t%2d\t", i, a[i].row, a[i].col, a[i].value);
//		printf("b[%d]\t%2d\t%2d\t%2d\n", i, b[i].row, b[i].col, b[i].value);
//	}
//}
//
//// 4.교재 그림 5,16의 이진트리를연결 표현으로 구성한 다음 중위순회, 전위순회, 후위순회로 구현하기
//// 4.1 중위순회 구현하기
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node* treePointer;
//typedef struct node {
//	char data;
//	treePointer leftChild, rightChild;
//} node;
//treePointer createNode(char data)
//{
//	treePointer newNode = (treePointer)malloc(sizeof(node));
//	newNode->data = data;
//	newNode->leftChild = NULL;
//	newNode->rightChild = NULL;
//	return newNode;
//}
//void inorder(treePointer ptr)
//{
//	if (ptr)
//	{
//		inorder(ptr->leftChild);
//		printf("%c ", ptr->data);
//		inorder(ptr->rightChild);
//	}
//}
//int main(void)
//{
//	treePointer n1 = createNode('A');
//	treePointer n2 = createNode('B');
//	treePointer n3 = createNode('/');
//	treePointer n4 = createNode('C');
//	treePointer n5 = createNode('*');
//	treePointer n6 = createNode('D');
//	treePointer n7 = createNode('*');
//	treePointer n8 = createNode('E');
//	treePointer n9 = createNode('+');
//	n3->leftChild = n1;
//	n3->rightChild = n2;
//	n5->leftChild = n3;
//	n5->rightChild = n4;
//	n7->leftChild = n5;
//	n7->rightChild = n6;
//	n9->leftChild = n7;
//	n9->rightChild = n8;
//	printf("중위 순회 결과: ");
//	inorder(n9);
//}
//
//// 4.2 전위순회 구현하기
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node* treePointer;
//typedef struct node {
//	char data;
//	treePointer leftChild, rightChild;
//} node;
//treePointer createNode(char data)
//{
//	treePointer newNode = (treePointer)malloc(sizeof(node));
//	newNode->data = data;
//	newNode->leftChild = NULL;
//	newNode->rightChild = NULL;
//	return newNode;
//}
//void preorder(treePointer ptr)
//{
//	if (ptr)
//	{
//		printf("%c ", ptr->data);
//		preorder(ptr->leftChild);
//		preorder(ptr->rightChild);
//	}
//}
//int main(void)
//{
//	treePointer n1 = createNode('A');
//	treePointer n2 = createNode('B');
//	treePointer n3 = createNode('/');
//	treePointer n4 = createNode('C');
//	treePointer n5 = createNode('*');
//	treePointer n6 = createNode('D');
//	treePointer n7 = createNode('*');
//	treePointer n8 = createNode('E');
//	treePointer n9 = createNode('+');
//	n3->leftChild = n1;
//	n3->rightChild = n2;
//	n5->leftChild = n3;
//	n5->rightChild = n4;
//	n7->leftChild = n5;
//	n7->rightChild = n6;
//	n9->leftChild = n7;
//	n9->rightChild = n8;
//	printf("전위 순회 결과: ");
//	preorder(n9);
//}
//
//// 4.3 후위순회 구현하기
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct node* treePointer;
//typedef struct node {
//	char data;
//	treePointer leftChild, rightChild;
//} node;
//treePointer createNode(char data)
//{
//	treePointer newNode = (treePointer)malloc(sizeof(node));
//	newNode->data = data;
//	newNode->leftChild = NULL;
//	newNode->rightChild = NULL;
//	return newNode;
//}
//void postorder(treePointer ptr)
//{
//	if (ptr)
//	{
//		postorder(ptr->leftChild);
//		postorder(ptr->rightChild);
//		printf("%c ", ptr->data);
//	}
//}
//int main(void)
//{
//	treePointer n1 = createNode('A');
//	treePointer n2 = createNode('B');
//	treePointer n3 = createNode('/');
//	treePointer n4 = createNode('C');
//	treePointer n5 = createNode('*');
//	treePointer n6 = createNode('D');
//	treePointer n7 = createNode('*');
//	treePointer n8 = createNode('E');
//	treePointer n9 = createNode('+');
//	n3->leftChild = n1;
//	n3->rightChild = n2;
//	n5->leftChild = n3;
//	n5->rightChild = n4;
//	n7->leftChild = n5;
//	n7->rightChild = n6;
//	n9->leftChild = n7;
//	n9->rightChild = n8;
//	printf("후위 순회 결과: ");
//	postorder(n9);
//}