#ifndef CIRCULARQUEUE
#define CIRCULARQUEUE

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/**********************************************************************************
	Day la circular queue dung linked list
-Dau tien cac node duoc xem nhu la mot nguoi dung o 1 hang cho co dinh
	Khi xong node nay se duoc tra du lieu va xoa di (dequeue)
- Khi co node moi, ta se khoi tao va dua vao cuoi danh sach theo kieu FIFO (enqueue)
- De co the co su lien ket thi khi them moi node dau tien thi con tro next se luu dia chi node dau tien
	de luon luon khep kin
- Khi so luong node trong mot circular tang len trong 1 queue max thi dung them
- Day la abstract class theo tu duy OOP (de de su dung va debug)
- Viec xu ly io se co mot class khac lam
*********************************************************************************/

//Khoi tao cau truc 1 node
typedef struct node {
	int data;
	struct node* next;
} Node;

//Khoi tao cau truc 1 queue (o day ta su dung hang doi chi co 10 node toi da)
typedef struct queue {
	Node* front;
	Node* rear;
	unsigned int limit; // toi da 10 node 
} Queue;

//Ham khoi tao 1 node co ban
Node* creNode(int data) {
	Node* newNode = (Node* )malloc(sizeof(Node));
	if (newNode == NULL) {
        return NULL; //kiem tra viec cung cap bo nho heap co loi hay khong
    }
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void initQueue(Queue* myQueue){
	//Khoi tao mot queue
	myQueue->front = myQueue->rear = NULL;
	myQueue->limit = 0; //Khoi tao gia tri bat dau
}

int isQueueEmpty(Queue* myQueue){
	//Khi so dem limit queue == 0 co nghia la queue dang rong
	return (myQueue->limit == 0)? 1 : 0;
}

int isQueueFull(Queue* myQueue) {
	//Khi so dem limit queue tang len == voi gia tri toi da (10) la day
	return (myQueue->limit == MAX)? 1 : 0;
}

void enQueue(Queue* myQueue, int value) {
	//Khoi tao truoc, co mot node moi vao trong queue
	Node* nwNode = creNode(value);
	
	//Bat dau them mot node moi vao queue
	//Neu la moi thi rear va front cung tro toi 1 node moi
	if(!isQueueEmpty(myQueue) && nwNode != NULL) {
		nwNode->next = myQueue->rear->next;
		myQueue->rear->next = nwNode; //tro toi node moi
		myQueue->rear = nwNode;		// thay doi rear
	}
	else {
		//Neu khoi tao lan dau
		myQueue->front = myQueue->rear = nwNode;
		myQueue->rear->next = myQueue->front;
	}

	myQueue->limit += 1; //tang luong so dem queue
}

//Hien thi thong tin dau tien cua queue
Node* popFront(Queue* myQueue) {
	return myQueue->front;
}

// Lay ra node o qua queue va sau do huy
// Giong nhu mot nguoi buoc len thong bao va roi khoi hang doi
// O day ta chi tha thong tin, con viec roi khoi va xoa thong tin se do luc
// user yeu cau se lay thong tin va lam cong viec don dep
// Neu xoa o day se lam mat du lieu tra ve, gay Bug
Node* deQueue(Queue* myQueue) {
	Node* tmp = myQueue->front;
	if(myQueue->limit > 1) {
		myQueue->front = myQueue->front->next; //front chi node ke tiep
		myQueue->rear->next = myQueue->front;
		myQueue->limit--;
		return tmp;
	}
	//Neu mot queue chi con 1 node duy nhat 
	// Thi khi dequeu ta cung can reset lai queue vi luc nay queue rong hoan toan
	initQueue(myQueue);
	return tmp;	
}

#endif
