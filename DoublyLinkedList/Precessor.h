#ifndef PRECESSOR
#define PRECESSOR

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* prev;
	struct Node* next;
	int data;	
} NODE;

typedef struct DoubLinkList {
	NODE* head;
	NODE* tail;	
} DOUBLINKLIST;

NODE* creNode(DOUBLINKLIST* myList ,int data) {
	NODE* p = (NODE*) malloc(sizeof(NODE));	
	p->prev = p->next = NULL; //Node dau tien thi thi cac vi tri tro la NULL		
	p->data = data;		
	return p; //tra ve dia chi con tro Node muon khoi tao
}

void initFirst(DOUBLINKLIST* myList) {
	myList->head = myList->tail = NULL; 
}

int isEmpty(DOUBLINKLIST* myList) {
	return (myList->head == NULL) ? 1 : 0; //neu la danh sach rong thi tra ve 1, con lai thi tra ve 0
//	if(myList->head == NULL)
//		return 1;
	//return 0;
}

void insrtHeadNode(DOUBLINKLIST* myList, NODE* p) {
	if(isEmpty(myList)) 
		myList->head = myList->tail = p;			
	else {
		//p->prev = NULL; //vi da co tao san khi tao node
		p->next = myList->head;
		myList->head->prev = p;
		myList->head = p;
	}	
}

void insrtTailNode(DOUBLINKLIST* myList, NODE* p) {
	if(isEmpty(myList))
		myList->head = myList->tail = p; //cung tro den NODE p, vi khoi tao lan dau
	else {
		p->prev = myList->tail;
		myList->tail->next = p;
		myList->tail = p;
	}
}

void insrtRandomNode(DOUBLINKLIST* myList, NODE* q, NODE* p) { //q la vi tri Node muon chen them
	if(isEmpty(myList))
		myList->head = myList->tail = p;
	else {
		NODE* tmp = q->prev;
		//ta giai quyet theo khu vuc, next trc va prev sau
		p->next = q; //p next se tro vi tri q muon chen
		tmp->next = p; //tmp la vi tri trc q se tro p (tmp-> p -> q)
		q->prev = p; //ta lam them cac buoc con lai de ta hai chieu
		p->prev = tmp; //(tmp -><- p -><- q)
	}
}

void delHeadNode(DOUBLINKLIST* myList) { //xoa vi tri dau		
	if (isEmpty(myList))
		printf("You dont have a list yet!\n");
	else {
		NODE* tmp = myList->head; 
		myList->head = tmp->next;	//dau tien phai doi dia chi head truoc
		tmp->next = NULL;			//nen luon dat con tro Head dau tien
		
		//nhu z con tro Head se tro null va gay ra loi
		//tu do gay thoat chuong trinh
//		tmp->next = NULL;	
//		myList->head = tmp->next;
		myList->head->prev = NULL;
		free(tmp);
	}
}

void delTailNode(DOUBLINKLIST* myList) {
	if(isEmpty(myList)) 
		printf("You dont have a list yet!\n");
	else {
		NODE* tmp = myList->tail;
		myList->tail = tmp->prev;
		myList->tail->next = NULL;
		free(tmp);
	}
}

#endif
