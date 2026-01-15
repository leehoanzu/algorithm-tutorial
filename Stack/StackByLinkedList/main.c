#include <stdio.h>
#include <stdlib.h>

#include "StackManagement.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LINKEDLIST* myList = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
	//NODE* Node = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
	initLinkedList(myList);
	int choice;
	do {
		menu();
		printf("Please choose your option!\n");
		scanf("%d", &choice);
		doIt(myList, choice);
	} while(choice != 4);
	free(myList);
	return 0;
}
