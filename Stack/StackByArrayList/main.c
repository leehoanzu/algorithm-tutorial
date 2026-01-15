#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	STACK* myStack = (STACK* ) malloc(sizeof(STACK));
	initStack(myStack);
	int n = 0;
	while(n != 5) {
//		Menu.menu();
		menu();
		scanf("%d", &n); //thieu & la toi
		doIt(myStack, n);
	}
	free(myStack);
	return 0;
}
