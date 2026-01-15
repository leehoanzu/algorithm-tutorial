#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	QUEUE* myQueue = (QUEUE*)malloc(sizeof(QUEUE));
	initQueue(myQueue);
	int n = -1;
	while(n != 4) {
		menu();
		scanf("%d", &n);
		doIt(myQueue, n);
	}
	free(myQueue);
	return 0;
}
