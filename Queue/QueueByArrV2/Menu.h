#ifndef MENU
#define MENU

#include <stdio.h>
#include "SimpleQueue.h"
#include "QueueManagement.h"


void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 5; i++){
		printf("%d. Enqueue\n", ++i);
		printf("%d. Dequeue\n", ++i);
		printf("%d. PopQueue\n", ++i);
		printf("%d. Print Queue\n", ++i);
		printf("%d. Quit\n", ++i);	
	}		
}

void doIt (Queue* myQueue, int n) {
	
	switch (n) {
		case 1:
			inputQueue(myQueue);
			break;
		case 2:
			delQueue(myQueue);
			break;
		case 3:
			popQueue(myQueue);
			break;	
		case 4: 
			displayQueue(myQueue);
			break;		
		case 5: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

#endif
