#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"
#include "SimpleQueue.h"
#include "QueueManagement.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue* myQueue = (Queue*)malloc(sizeof(Queue));
	initQueue(myQueue);
	static int n = -1;
	while(n != 5) {
		menu();
		scanf("%d", &n);
		doIt(myQueue, n);
	}
	free(myQueue);
	
	return 0;
}
