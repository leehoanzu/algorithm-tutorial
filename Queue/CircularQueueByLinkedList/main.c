#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"
#include "QueueManagement.h"
#include "Menu.h"
#define CHOICE 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue* myQueue = (Queue*)malloc(sizeof(Queue));
	initQueue(myQueue);
	int num;
	do {
		menu(); //hien thi cac option
		printf("Please choose your option!\n"); //hien thi thong bao
		scanf("%d", &num); //nhap lua chon tu ban phim
		doIt(myQueue, num); //lam nhung lua chon
	} while(num != CHOICE); //neu la max choice se dong app
	return 0;
}
