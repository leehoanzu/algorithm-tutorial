#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>
#include "InformLinkList.h"
#include "Precessor.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 7; ){
		printf("%d. Add first list\n", ++i);
		printf("%d. Add last list\n", ++i);
		printf("%d. Add random position in your list\n", ++i);
		printf("%d. Remove first list\n", ++i);
		printf("%d. Remove last list\n", ++i);
		printf("%d. Print current list\n", ++i);
		printf("%d. Quit\n", ++i);	
	}		
}

void doIt (DOUBLINKLIST* myList, int n, int* length) {
	
	switch (n) {
		case 1:
			informInsrtHeadNode(myList, length);
			break;
		case 2:
			informInsrtTailNode(myList, length);
			break;
		case 3:
			informInsrtRandNode(myList, length);
			break;			
		case 4:
			informDelHeadNode(myList, length);
			break;	
		case 5:
			informDelTailNode(myList, length);
			break;
		case 6:
			printList(myList);
			break;	
		case 7: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

#endif

