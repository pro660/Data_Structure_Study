/* 4. 교재 그림 5.16의 이진트리를 연결 표현으로 구성한 다음
중위순회(프로그램 5.1), 전위순회(프로그램 5.2), 후위순회(프로그램 5.3) 구현하기 */

#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)\
 if (! ((p) = (treePointer)malloc(s))) {\
fprintf(stderr, "insufficient memory");\
exit(EXIT_FAILURE);\
}
typedef struct node* treePointer;
typedef struct node{
	char data;
	treePointer leftChild, rightChild;
};
void mallocRightChild(treePointer first, char data)
{	// 트리의 오른쪽 자식 생성.
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->rightChild = NULL;
	temp->data = data;
	temp->leftChild = NULL;
	first->rightChild = temp;
}
treePointer mallocLeftChild(treePointer first, char data)
{	// 트리의 왼쪽 자식 생성.
	treePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->rightChild = NULL;
	temp->data = data;
	temp->leftChild = NULL;
	first->leftChild = temp;
	return first->leftChild;
}
void arithmeticTree(treePointer root)
{	// (P. 221) 그림 5.16 이진트리 구현.
	treePointer Child;

	root->data = '+';
	mallocRightChild(root, 'E');
	Child = mallocLeftChild(root, '*');
	mallocRightChild(Child, 'D');
	Child = mallocLeftChild(Child, '*');
	mallocRightChild(Child, 'C');
	Child = mallocLeftChild(Child, '/');
	mallocRightChild(Child, 'B');
	Child = mallocLeftChild(Child, 'A');
}
void inorder(treePointer ptr)
{	// 중위 트리 순회
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}
void preorder(treePointer ptr)
{	// 전위 트리 순회
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr)
{	// 후위 트리 순회
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}
int main()
{
	treePointer root;
	MALLOC(root, sizeof(*root));
	arithmeticTree(root);
	printf("중위 순회: ");
	inorder(root);
	printf("\n전위 순회: ");
	preorder(root);
	printf("\n후위 순회: ");
	postorder(root);
	printf("\n");
}
