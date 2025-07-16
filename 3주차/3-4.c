// 4. 교재 그림 5.16의 이진트리를 연결 표현으로 구성한 다음
// 중위순회(프로그램 5.1), 전위순회(프로그램 5.2), 후위순회(프로그램 5.3) 구현하기
// 4.1 중위순회 구현하기 ( 프로그램 5.1 )
#include <stdio.h>
#include <stdlib.h>
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;
treePointer createNode(char data) 
{
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}
void inorder(treePointer ptr)
{
	if (ptr) 
	{
		inorder(ptr->leftChild);
		printf("%c ", ptr->data);
		inorder(ptr->rightChild);
	}
}
int main(void) 
{
	treePointer n1 = createNode('A');
	treePointer n2 = createNode('B');
	treePointer n3 = createNode('/');   
	treePointer n4 = createNode('C');
	treePointer n5 = createNode('*');     
	treePointer n6 = createNode('D');
	treePointer n7 = createNode('*');     
	treePointer n8 = createNode('E');
	treePointer n9 = createNode('+');     
	n3->leftChild = n1;
	n3->rightChild = n2;
	n5->leftChild = n3;
	n5->rightChild = n4;
	n7->leftChild = n5;
	n7->rightChild = n6;
	n9->leftChild = n7;
	n9->rightChild = n8;
	printf("중위 순회 결과: ");
	inorder(n9);
}

// 4.2 전위순회 구현하기 ( 프로그램 5.2 )
#include <stdio.h>
#include <stdlib.h>
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;
treePointer createNode(char data)
{
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}
void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%c ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
int main(void)
{
	treePointer n1 = createNode('A');
	treePointer n2 = createNode('B');
	treePointer n3 = createNode('/');
	treePointer n4 = createNode('C');
	treePointer n5 = createNode('*');
	treePointer n6 = createNode('D');
	treePointer n7 = createNode('*');
	treePointer n8 = createNode('E');
	treePointer n9 = createNode('+');
	n3->leftChild = n1;
	n3->rightChild = n2;
	n5->leftChild = n3;
	n5->rightChild = n4;
	n7->leftChild = n5;
	n7->rightChild = n6;
	n9->leftChild = n7;
	n9->rightChild = n8;
	printf("전위 순회 결과: ");
	preorder(n9);
}

// 4.3 후위순회 구현하기 ( 프로그램 5.3 )
#include <stdio.h>
#include <stdlib.h>
typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} node;
treePointer createNode(char data)
{
	treePointer newNode = (treePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}
void postorder(treePointer ptr)
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c ", ptr->data);
	}
}
int main(void)
{
	treePointer n1 = createNode('A');
	treePointer n2 = createNode('B');
	treePointer n3 = createNode('/');
	treePointer n4 = createNode('C');
	treePointer n5 = createNode('*');
	treePointer n6 = createNode('D');
	treePointer n7 = createNode('*');
	treePointer n8 = createNode('E');
	treePointer n9 = createNode('+');
	n3->leftChild = n1;
	n3->rightChild = n2;
	n5->leftChild = n3;
	n5->rightChild = n4;
	n7->leftChild = n5;
	n7->rightChild = n6;
	n9->leftChild = n7;
	n9->rightChild = n8;
	printf("후위 순회 결과: ");
	postorder(n9);
}