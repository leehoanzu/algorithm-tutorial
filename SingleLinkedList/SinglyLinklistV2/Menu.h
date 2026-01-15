#ifndef MENU
#define MENU

#include <stdio.h>
#include "Precessor.h"
#include "EditLinklist.h"

void menu() {
		
	printf("\nPlease choose your selection: \n");
//	printf("1. Create first list");
	for(int i = 0; i < 8; i++){
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

void doIt (LINKLIST* myList, NODE* p, int n, int* length) {
	
	switch (n) {
		case 1:
			informAddFirst(myList, p, length);
			break;
		case 2:
			informAddTail(myList, p, length);
			break;
		case 3:
			informAddRandomeNode(myList, p, length);	
			//free(tmp); //can than de sai
			break;			
		case 4:
			informDeleteHeadNode(myList, length);			
			printf("\nYour list after removing Head\n");
			printList(myList); //in danh sach sau khi xoa
			break;	
		case 5:
			informDeleteTailNode(myList, length);
			printf("\nYour list after removing tail\n");
			printList(myList); //in danh sach sau khi xoa			
			break;
		case 6:
			informDeleteRandomeNode(myList, length);
			printf("\nYour list after removing randome\n");
			//printList(myList); //in danh sach sau khi xoa	
								//in cho nay k hop ly nhe
								//vi sau khi nhap tao lao van in la k duoc
			break; //thieu break la tieu nhes
		case 7:
			printList(myList);
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
