#ifndef QUEUEBYUSINGARRAY
#define	QUEUEBYUSINGARRAY

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 //dinh nghia size cua queue nay la 10

typedef struct QUEUE {
	int arr[SIZE];
	int front; 
	int rear;
} QUEUE;

void initQueue(QUEUE* myQueue) {
	myQueue->front = myQueue->rear = -1;
}

int isOverFlow(QUEUE* myQueue) {
	if (myQueue->rear >= SIZE - 1)
		return 1;
	return 0;
}

int isUnderFlow(QUEUE* myQueue) {
	if ((myQueue->rear == -1) || (myQueue->front > myQueue->rear))
		return 1;
	return 0;
}

void enQueue(QUEUE* myQueue) {
	int param; //thong so dau vao
	if(isOverFlow(myQueue))
		printf("OVERFLOW!");
	else {
		printf("Input your value, please!\n");
		scanf("%d", &param);
		if(myQueue->front == -1)
			myQueue->front = 0;
		myQueue->rear++;
		myQueue->arr[myQueue->rear] = param;
		printf("Your act has just done!\n");
	}
}

void deQueue (QUEUE* myQueue) {
	//int param;
	if(isUnderFlow(myQueue))
		printf("UNDERFLOW!\n");
	else {
		printf("Your %d has been deledted\n", myQueue->arr[myQueue->front]);
		myQueue->front++;		
	}
}

void dispQueue (QUEUE* myQueue) {
	if(isUnderFlow(myQueue))
		printf("You dont have queue!\n");
	else {
		//printf("%d ", myQueue->arr[0]);
		for(int i = myQueue->front; i <= myQueue->rear; i++)
			printf("%d ", myQueue->arr[i]);
	}
}
#endif
