#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h"
#include "InformLinkList.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 8; ){
		printf("%d. Add first list\n", ++i);
		printf("%d. Add last list\n", ++i);
		printf("%d. Add random position in your list\n", ++i);
		printf("%d. Remove first list\n", ++i);
		printf("%d. Remove last list\n", ++i);
		printf("%d. Remove randome list\n", ++i);
		printf("%d. Print current list\n", ++i);
		printf("%d. Quit\n", ++i);	
	}		
}

void doIt (CIRLINKLIST* myList, int n, int* length) {
	
	switch (n) {
		case 1:
			informAddHead(myList, length);			
			break;
		case 2:
			informAddTail(myList, length);
			break;
		case 3:
			informAddRandomeNode(myList, length);			
			break;			
		case 4:
			informdelFirstList(myList, length);
			break;	
		case 5:
			informdelTailList(myList, length);
			break;
		case 6:
			informdeRandomeList(myList, length);
			break; 
		case 7:
			printList(myList, length);
			printf("\n");
			break;	
		case 8: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

#endif

