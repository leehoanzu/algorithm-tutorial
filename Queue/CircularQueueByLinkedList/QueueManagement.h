#ifndef QUEUEMANAGEMENT
#define QUEUEMANAGEMENT

#include<stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"
#define MAX 10

/*********************************************************************************
	Day la class xu ly tac vu cua nguoi dung trong 1 queue
- Khi thuc hien 1 tac vu them bot, hay tong hop kiem tra se duoc thuc hien o day
- Tranh thuc hien trong class queue vi nhieu tac vu va kho kiem xoat
- O day neu kiem tra va xua se khong tac dong truc tiep nen co the thay doi va
	tuy chinh theo
*********************************************************************************/

// Nhap vao gia tri cua node truoc khi them vao queue
// Ta se kiem tra queue da day hay chua va bat dau thuc hien them implements
// Neu day thi khong them de tranh hien tuong overflow
void inputQueue(Queue* myQueue) {
	if(!isQueueFull(myQueue)) {
		int value;
		do{
			printf("Please input positive value into queue: ");
			scanf("%d", &value);
		} while (value <= 0);	//Bat buoc nguoi dung nhap gia tri duong
		
		printf("\nYour action is done\n");	
		enQueue(myQueue, value); //tao mot node moi va them vao queue voi
								//value vua nhap
	}	
	else
		printf("Queue is full now\n");	
}

//Hien thi thong tin node o vi tri dau queue
void popQueue(Queue* myQueue) {
	//Ta co the su dung anonymous object thay vi mot node tam
	//nhung o day se tach bach de hieu ro khai niem va them bot
	Node* popNode = popFront(myQueue);
	if(popNode != NULL)
		printf("This is the value of first queue and address: %d vs %p", popNode->data, &popNode);
	else
		printf("Your queue is currently empty\n");
}

//Day la ham hien thi va sau do xoa mot node khoi queue
// Phai luon kiem tra queue co node nao khong de tranh hien tuong underflow
// O day ta phai luon nho free vung nho node nay sau khi doc de tranh memory leak
void delQueue(Queue* myQueue) {
	if(!isQueueEmpty(myQueue)) {
		int a;
		do {
			printf("Please input how many times do you want to dequeue (1 -> %d): ", myQueue->limit);
			scanf("%d", &a);
		} while (a <= 0 || a > myQueue->limit + 1); //doc may thong tin trong queue
													// Bat buoc doc trong gioi han
													// Boi vi myQueue->limit bat dau = 0
													// nen viec cong 1 se tuong ung voi so dem
													// hang ngay cho nguoi dung
		
		for(int i = 0; i < a; i++) {
			Node* rsNode = deQueue(myQueue); // tao node tam hung thong tin
			printf("You have delele %d out of queue\n", rsNode->data);
			free(rsNode); //delete nhen
		}
	}
	else
		printf("You do not have any queue yet\n");

}

//Hien thi tong quan cac node co trong queue
void displayQueue(Queue* myQueue) {
	if(!isQueueEmpty(myQueue)) {
		Node* tmp = myQueue->front; //Bat dau hien thi thong tin o vi tri dau tien
		printf("This is full queue you already have\n");
		for(int i = 0; i < myQueue->limit; i++, tmp = tmp->next) //sau do hien thi cac thong tin tiep theo
			printf("%d -> ", tmp->data);
		printf("NULL\n");
		//khong the su dung (myQueue->front->next + i)->data boi vi
		//Linked list lua cac gia tri dia chi roi rac va lien ket thong qua con tro luu dia tri next
		//Khac voi array la cac dia chi lien tiep nhau
		//nen viec tang len (+i) se nhay toi vung dia chi khac va in ra du lieu sai
	}
	else 
		printf("You dont have any implements yet\n");
}

#endif
