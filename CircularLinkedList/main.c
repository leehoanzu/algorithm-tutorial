#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"
#include "Precessor.h"
#include "InformLinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CIRLINKLIST* myList = (CIRLINKLIST*) malloc(sizeof(CIRLINKLIST));
	initFirstNode(myList); //k co se gay ra loi
	int n;
	unsigned int length = 0;
	
	do {
		menu();
		printf("My selection is: ");
		scanf("%d", &n);
		doIt(myList, n, &length);
	} while(n != 8);
	
	return 0;
}
