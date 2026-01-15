#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 4; i++){
		printf("%d. Enqueue\n", ++i);
		printf("%d. Dequeue\n", ++i);
		printf("%d. Display\n", ++i);
		printf("%d. Quit\n", ++i);
	}		
}

void doIt (LINKEDLIST* myList, int n) {
	switch (n) {
		case 1:
			doEnQueue(myList);
			break;
		case 2:
			deQueue(myList);
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
