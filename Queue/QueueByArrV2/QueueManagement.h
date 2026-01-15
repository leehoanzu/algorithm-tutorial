#ifndef QUEUEMANAGEMENT
#define QUEUEMANAGEMENT

#include<stdio.h>
#include "SimpleQueue.h"
#define MAX 10
#define NULL_VALLUE -1

void inputQueue(Queue* myQueue) {
	int value;
	if(!isQueueFull(myQueue)) {
		do{
			printf("Please input positive value into queue: ");
			scanf("%d", &value);
		} while (value < 0);	
		printf("\nYour action is done\n");	
		enQueue(myQueue, value);
	}	
	else
		printf("Queue is full now\n");	
}

void popQueue(Queue* myQueue) {
	int value = popFront(myQueue);
	if(value != NULL_VALLUE)
		printf("This is the value of first queue: %d\n", value);
	else
		printf("Your queue is currently empty\n");
}

void delQueue(Queue* myQueue) {
	if(!isQueueEmpty(myQueue)) {
		int a;
		do {
			printf("Please input how many times do you want to dequeue (1 -> %d): ", myQueue->nRear + 1);
			scanf("%d", &a);
		} while (a <= 0 || a > myQueue->nRear + 1);
		
		
		for(int i = 0; i < a; i++) {
			int rslt = deQueue(myQueue);
		    if (rslt == NULL_VALLUE)
		        break;
		
			printf("You have delele %d out of queue\n", rslt);
		}
	}
	else
		printf("You do not have any queue yet\n");
	
}

void displayQueue(Queue* myQueue) {
	if(!isQueueEmpty(myQueue)) {
		printf("This is full queue you already have\n");
		for(int i = myQueue->nFront; i <= myQueue->nRear; i++)
			printf("%d -> ", myQueue->arr[i]);
		printf("NULL VALUE\n");
	}
	else 
		printf("You dont have any implements yet\n");
}

#endif
