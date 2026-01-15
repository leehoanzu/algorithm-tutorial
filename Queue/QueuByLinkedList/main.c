#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "Queue.h"
#include "Menu.h"
int main(int argc, char *argv[]) {
	LINKEDLIST* myList = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
	initList(myList);
	int choice;
	do {
		menu(); //hien thi cac option
		printf("Please choose your option!\n"); //hien thi thong bao
		scanf("%d", &choice); //nhap lua chon tu ban phim
		doIt(myList, choice); //lam nhung lua chon
	} while(choice != 4); //neu la 4 se dong app
	return 0;
}
