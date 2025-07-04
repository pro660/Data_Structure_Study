#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    } //매크로 함수에서 역슬래시는 줄이 끝나지 않음을 표시하는 것(\뒤에 공백 X)   

typedef struct element{
    int key;
} element;

typedef struct queue *queuePointer;
typedef struct queue{
    element data;
    queuePointer link;
} queue;

queuePointer front, rear;

void queueEmpty();
void addq(element item);
element deleteq();
void printList();



int main(){
    int n, addn;
    
    while(1){
	
	    printf("\nPress 1 to add, 2 to delete, 3 to print, or 0 to exit : ");
	    scanf("%d", &n);
	    
		switch(n){
			case 1:
				printf("Enter the numbers to add : ");
				scanf("%d", &addn);
				addq((element){ .key = addn });
				break;
			case 2:
				deleteq();
				printf("deleted\n");
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
    queuePointer temp = front;
    
    if(front){
	    printf("The list contains: ");
	    printf("front->");
	    
	    for(; temp; temp=temp->link)
	        printf("%4d", temp->data.key);
	        
	    printf("   ->rear");
	}
	else
		printf("The list is Empty");

    printf("\n");
}

void addq(element item){
    queuePointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->data = item;
    temp->link = NULL;
    if(front)
        rear->link = temp;
    else 
        front = temp;
    
        rear = temp;
}

element deleteq(){
    queuePointer temp = front;
    element item;
    if(!temp)
        queueEmpty();
    item = temp->data;
    front = temp->link;
    free(temp);
    
    return item;
}

void queueEmpty(){
    fprintf(stderr, "queue is Empty already\n");
    exit(EXIT_FAILURE);
}
