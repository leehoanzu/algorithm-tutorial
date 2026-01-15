#ifndef PRECESSOR
#define PRECESSOR

#include <stdio.h>
#include <stdlib.h>

//dau tien la tao node va danh sach giong nhu singly link list
typedef struct Node { //tao node giong nhu singly Link List
	int data;
	struct Node* next;	
} NODE;

typedef struct CirLinkList {
	NODE* head;
	NODE* tail;	
} CIRLINKLIST;

void initFirstNode(CIRLINKLIST* myList) {
	myList->head = myList->tail = NULL; //gan gia tri ban dau
}

int isEmpty(CIRLINKLIST* myList) {
	if (myList->head == NULL)
		return 1;
	return 0;
}

NODE* creNode(CIRLINKLIST* myList, int data) { //phai tra ve gia tri de con reuse
	NODE* p = (NODE*) malloc(sizeof(NODE));
	
//	if (isEmpty(myList)) { //neu la nap lan dau
//		myList->head = myList->tail = p;
//		p->data = data;
//		return p;
//	}
//	else 
//		p->data = data;
//	return p;
// viec tao k nen kiem tra danh sach rong hay dac. Dieu nay k can thiet va se gay ra loi
// do la se bo qua truong hop dau tien trong insert NODE vao danh sach
	p->data = data;
	return p;
} 

void insrtHeadNode(CIRLINKLIST* myList, NODE* p) { //DUA DIA CHI P CON TRO MUUON ADD
	if(isEmpty(myList)) {
		myList->head = myList->tail = p;
		p->next = myList->head;
	}
	else {
		p->next = myList->head;
		myList->head = p;
		myList->tail->next = myList->head;	
	}
}

void insrtTailNode(CIRLINKLIST* myList, NODE* p) { //DUA DI CHI CON MUON ADD
	if(isEmpty(myList)) {
		myList->head = myList->tail = p;
		p->next = myList->head; //vi day la cirular linklist nen khi insert lan dau thi ta cung phai tro quay lai dau
		//printf("oppps"); thu nghiem de biet co chuong trinh co chay vao k, de tranh bi bug
	}		
	else { //rat giong voi add vao dau
			//vi no la mot vong tron;
			//khac la vung dia chi ta dua ve o duoi nhu dong 56
		myList->tail->next = p;
		p->next = myList->head;	
		myList->tail = p;
		 //dia chi de tro tiep theo cua duoi la mot dia chi cua con tro mo
	}	
}

void insrtRandomeNode(CIRLINKLIST* myList, NODE* p, NODE* q) { //NODE* q la khai bao NODE truoc vi tri can insrt
																//NODE* p la khai bao NODE muon insrt vao
	
	p->next = q->next; //dau tien la 2 chang cung tro 1 nang
	q->next = p; //sau do q se tro ban moi vi cho nay da bi dich sang phai 	
}

void delFirstList(CIRLINKLIST* myList, int* length) {
	NODE* tmp = myList->head;
	if ((*length) + 1 == 1)
		initFirstNode(myList);
	else {
		myList->tail->next = tmp->next;
		myList->head = tmp->next;
	}		
	free(tmp); //xoa so cai nha ma tmp dang tro
}

void delTailList(CIRLINKLIST* myList, NODE* q, int* length) { //con tro q la con tro dung trc vi tri Tail
	NODE* tmp = myList->tail;
	if ((*length) + 1 == 1)
		initFirstNode(myList);
	else {
		q->next = tmp->next;
		myList->tail = q;
	}		
	free(tmp); //xoa so cai nha ma tmp dang tro
}

void delRandList(CIRLINKLIST* myList, NODE* q, int* length) { //con tro q la con tro dung trc vi tri bat ki
	NODE* tmp = q->next;
	if ((*length) + 1 == 1)
		initFirstNode(myList);
	else 
		q->next = tmp->next;
	free(tmp); //xoa so cai nha ma tmp dang tro
}
#endif
