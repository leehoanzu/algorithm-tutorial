#ifndef STACKBYUSINGARRAY
#define	STACKBYUSINGARRAY
//khong nen dat ten dinh nghia trung voi ten object
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//khai báo dinh nghia doi tuong STACK
typedef struct STACK{
    unsigned int top;
    int arr[10];
} STACK;

//Set up gia tri ban dau mac dinh cho vi tri top la -1:
//co nghia la chua co gia tri nao duoc push vao trong stack
void initStack(STACK* myStack ) {
	myStack->top = -1;
}

//kiem tra stack da day hay chua
int isFullStack(STACK* myStack) {
//	if (myStack->top == SIZE - 1)
//		return 1; //neu stack day thi la 1 
//	return 0;
	return (myStack->top == SIZE - 1)? 1 : 0;
}

//kiem tra stack da duoc imple parameter nao chua
int isEmpty(STACK* myStack) {
//	if (myStack->top == -1)
//		return 1; //neu la rong thi la true
//	return 0;		
	return (myStack->top == -1)? 1 : 0;
}

//them tham so vao stack
void push(STACK* myStack, int param) {
 //neu chua day thi bat dau them vao tu dau
	myStack->top++;
	myStack->arr[myStack->top] = param;
}

int pop(STACK* myStack) {
	int ele = myStack->arr[myStack->top]; //LIFO lay thang cuoi cung ra xoa va doc
	myStack->top--;
	return ele;
}


#endif
