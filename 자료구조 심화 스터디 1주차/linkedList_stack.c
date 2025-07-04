#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    } //매크로 함수에서 역슬래시는 줄이 끝나지 않음을 표시하는 것(\뒤에 공백 X)   

typedef struct element{
    char key;
} element;

typedef struct stack *stack_pointer;
typedef struct stack{
    element item;
    stack_pointer link;
} stack;

void stackEmpty();
void push(element item);
element pop();
void printList();

stack_pointer top = NULL;

int main(){
    int n;
    char addn;
    
    while(1){
	
	    printf("\nPress 1 to push, 2 to pop, 3 to print, or 0 to exit : ");
	    scanf("%d", &n);
	    
		switch(n){
			case 1:
				printf("Enter the character to push : ");
				scanf(" %c", &addn);
				push((element){ .key = addn });
				break;
			case 2:
				pop();
				printf("popped\n");
				break;
			case 3:
				printList();
				break;
			case 0: 
				printf("Exit the Program");
				exit(EXIT_FAILURE);
			default:
				printf("Invalid input. Try again.\n");
		}
	}
    
    return 0;
}

void printList(){
    stack_pointer temp = top;
    if(top){
    	printf("The list contains: ");
    	printf("top->");
    	for(; temp; temp=temp->link)
        	printf("%4c", temp->item.key);
    	printf("  ->NULL");
	}
	else
		printf("Stack is Empty");
    
    printf("\n");
}

void push(element item){
    stack_pointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->item = item;
    temp->link = top;
    top = temp;
}

element pop(){
    stack_pointer temp = top;
    element item;
    if(!temp)
        stackEmpty();
    item = temp->item;
    top = temp->link;
    free(temp);
    
    return item;
}

void stackEmpty(){
    fprintf(stderr, "stack is Empty already\n");
    exit(EXIT_FAILURE);
}
