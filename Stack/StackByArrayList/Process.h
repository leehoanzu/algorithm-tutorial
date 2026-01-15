#ifndef Process
#define	Process

#include <stdio.h>
#include "Stack.h"

void doPush(STACK* myStack) {
	int param;
	if(isFullStack(myStack))
		printf("Your stack is already full!\n");
	else {
		printf("Input your parameter\n");
		scanf("%d", &param);
		push(myStack, param);
		printf("Your act has just done!\n");
	}
		
}

void doPop(STACK* myStack) {
	if(isEmpty(myStack))
		printf("You dont have any parameter to show!\n");
	else		
		printf("You has just pop %d from Stack\n", pop(myStack));
}

//hien thi ra man hinh stack
void dispStack(STACK* myStack) {
	if(isEmpty(myStack))
		printf("You dont have any parameter to show!\n");
	else {
		for(int i = myStack->top; i >= 0; i--) {
			printf("%d ", myStack->arr[i]);
		}
		printf("\n"); //xuong hang sau khi in ra stack	
	}
}

//Kiem tra stack
void checkStack(STACK* myStack) {
	if(isEmpty(myStack)) 
		printf("You have not implemented any parameter yet!\n");
	else
		printf("You have %d implement in your stack\n", myStack->top + 1);

}



#endif
