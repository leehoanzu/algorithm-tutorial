#ifndef SIMPLEQUEUE
#define SIMPLEQUEUE

#include <stdio.h>
#define MAX 10
#define NULL_VALLUE -1
// Day la simple queue boi vi khi muon enqueue ma queue tran thi ta tinh tien queue len va tiep tuc
// Vi du arr[10] duoc enqueue ca 10 va muon tiep tuc
// thi ta doi arr len ve phia dau mang. Boi khi enqueue hay dequeue deu co xu huong di ve phia rear
// nen se co cho trong queue
// Ta se doi len va tiep tuc dien

typedef struct queue {
	int arr[MAX];
	int nRear;
	int nFront;
} Queue;

void initQueue(Queue* myQueue){
	myQueue->nFront = 0; //vi tri ban dau la dau hang doi queue
	myQueue->nRear = -1;
	for(int i = 0; i < MAX; i++)
		myQueue->arr[i] = NULL_VALLUE;
}

int isQueueEmpty(Queue* myQueue){
	//queue rong khi va chi khi mang[front] rong hoac chi so fornt lon hon chi so rear
	return (myQueue->arr[myQueue->nFront] == NULL_VALLUE)? 1 : 0;
}

int isQueueFull(Queue* myQueue) {
	//Queue day khi va chi khi day tong so luong danh sach bang MAX
	return ((myQueue->nRear - myQueue->nFront + 1) == MAX)? 1 : 0;
}

void enQueue(Queue* myQueue, int value) {
	if((myQueue->nRear + 1) == MAX) {
		for(int i = myQueue->nFront; i < myQueue->nRear + 1; i++) {
			myQueue->arr[i - myQueue->nFront] = myQueue->arr[i];
		}
		myQueue->nRear = MAX - myQueue->nFront - 1;
		myQueue->nFront = 0;
	}
//	myQueue->nRear++;
	myQueue->arr[++myQueue->nRear] = value;


}

//Hien thi thong tin dau tien cua queue
int popFront(Queue* myQueue) {
//	if(!isQueueEmpty(myQueue)) 
//		return myQueue->arr[myQueue->nFront];
//	return NULL_VALLUE
	return (!isQueueEmpty(myQueue))? myQueue->arr[myQueue->nFront] : NULL_VALLUE;
}

int deQueue(Queue* myQueue) {
	int x = myQueue->arr[myQueue->nFront];
	myQueue->nFront += 1;
	return x;
}

#endif
