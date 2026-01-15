#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include "StackManagement.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 4; i++){
		printf("%d. Pop\n", ++i);
		printf("%d. Push\n", ++i);
		printf("%d. Display\n", ++i);
		printf("%d. Quit\n", ++i);
	}		
}

void doIt (LINKEDLIST* myList, int n) {
	switch (n) {
		case 1:
			doPush(myList);
			break;
		case 2:
			doPop(myList);
			break;
		case 3:
			display(myList);
			break;			
		case 4: 
			printf("bye bye!");
			break;
		default :
			break;	
	}
}

#endif
