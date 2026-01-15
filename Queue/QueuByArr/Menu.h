#ifndef MENU
#define MENU

#include <stdio.h>
#include "Queue.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 4; i++){
		printf("%d. Enqueue\n", ++i);
		printf("%d. Dequeue\n", ++i);
		printf("%d. Print Queue\n", ++i);
		printf("%d. Quit\n", ++i);	
	}		
}

void doIt (QUEUE* myQueue, int n) {
	
	switch (n) {
		case 1:
			enQueue(myQueue);
			break;
		case 2:
			deQueue(myQueue);
			break;
		case 3:
			//printf("case 3\n");
			dispQueue(myQueue);
			break;			
		case 4: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

#endif
