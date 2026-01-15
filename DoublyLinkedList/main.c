#include <stdio.h>
#include <stdlib.h>

#include "Precessor.h"
#include "InformLinkList.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	DOUBLINKLIST* myList = (DOUBLINKLIST*) malloc(sizeof(DOUBLINKLIST));
	initFirst(myList); //rat quang trong
	unsigned int length = 0;  
	int n;
	while(n != 7) {
		menu();
		printf("Please choose your option: ");
		scanf("%d", &n);
		doIt(myList, n, &length);
	}
	return 0;
}
