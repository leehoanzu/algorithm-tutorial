#ifndef MENU
#define MENU

#include <stdio.h>
#include "Stack.h"
#include "Process.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 5; i++){
		printf("%d. Push Stack\n", ++i);
		printf("%d. Pop Stack\n", ++i);
		printf("%d. Print Stack\n", ++i);
		printf("%d. Check Stack\n", ++i);
		printf("%d. Quit\n", ++i);	
	}		
}

void doIt (STACK* myStack, int n) {
	
	switch (n) {
		case 1:
			doPush(myStack); //nen tao ra 1 doi tuong nhap xuat rieng
			break;
		case 2:
			doPop(myStack);
			break;
		case 3:
			dispStack(myStack);
			break;			
		case 4: 
			checkStack(myStack);
			break;
		case 5: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

#endif
