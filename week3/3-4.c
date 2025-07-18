/* 트리의 전위, 중위, 후위 순회 */
#include <stdio.h>
#include <stdlib.h>   // malloc, free

typedef struct node {
    char data;
    struct node *leftChild;
    struct node *rightChild;
} node;

typedef node* treePointer;

// createNode는 char를 인자로 받고, node 크기만큼 메모리 할당
treePointer createNode(char data) {
    treePointer newNode = malloc(sizeof(node));
    if (!newNode) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->data       = data;
    newNode->leftChild  = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

/** 중위 트리 순회 */
void inorder(treePointer ptr){
    if(ptr){
        inorder(ptr->leftChild);
        printf("%c", ptr->data);
        inorder(ptr->rightChild);
    }
}

/** 전위 순회 */
void preorder(treePointer ptr){
    if(ptr){
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

/** 후위 순회 */
void postorder(treePointer ptr){
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c", ptr->data);
    }
}

int main(void) {
    treePointer n = createNode('+');
    treePointer root = n; // root를 기억할 임시저장공간

    n->leftChild = createNode('*');
    n->rightChild = createNode('E'); n = n->leftChild;
    n->leftChild = createNode('*');
    n->rightChild = createNode('D'); n = n->leftChild;
    n->leftChild = createNode('/');
    n->rightChild = createNode('C'); n = n->leftChild;
    n->leftChild = createNode('A');
    n->rightChild = createNode('B');

    printf("Inorder Traversal tree : "); inorder(root);
    printf("\npreorder Traversal tree : "); preorder(root);
    printf("\npostorder Traversal tree : "); postorder(root);
    return 0;
}