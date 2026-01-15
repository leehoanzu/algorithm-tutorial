#ifndef STACKMANAGEMENT
#define	STACKMANAGEMENT

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data; //du lieu cua node 
	struct Node* pre; //con tro chua dia chi ke tiep
	//phai tao ten node trc khi doi vung ten struct thanh bien khac
} NODE; //kieu du lieu nay ten la Node //sai gì nè

typedef struct {
	NODE* top; //con tro chua vung du lieu moi dua vao FIFO	
} LINKEDLIST; //tap hop stack theo cau truc FIFO la 1 dang danh sach
			//con tro theo kieu add vao dau danh sach
			
static void initLinkedList(LINKEDLIST* myList) {
	myList->top = NULL; //luon khoi tao gia tri ban dau cua danh sach o vi tri NULL
						//O vi tri 0x00, neu k se k xac dinh duoc vi tri ban dau va gay loi
}

static int isEmtyList(LINKEDLIST* myList) { //kiem tra danh sach co rong 
	return myList->top == NULL ? 1 : 0; //tra ve 1 neu la NULL va nguoc lai
}


NODE* creNode(int data) { //tao node
	NODE* Node = (NODE*) malloc(sizeof(NODE)); //khoi tao 1 vung khong gian cho Node trong Heap
	Node->data = data; //gan gia tri data cho node
	Node->pre = NULL;
//	Node->pre = prePtr; //gan dia tri cua Node truoc do
//						//vi day la stack nap du lieu theo kieu FIFO
	return Node;
}

static void push(LINKEDLIST* myList, NODE* nodePtr) { //them data vao dau danh sach
	if(isEmtyList(myList)) { //neu la gia tri tao moi thi con tro pre la NULL
		myList->top = nodePtr; //dau tien thi top la gia tri nodePtr
		nodePtr->pre = NULL; //dau tien thi con tro pre luon la NULL
	}
	else {
		nodePtr->pre = myList->top; //chen vao vi tri dau thi sau no se la thang top cu 
									//chua thay doi
		myList->top = nodePtr;
	}
}

static NODE* pop(LINKEDLIST* myList) { //xoa data o dau danh sach va hien thi ra
	if(isEmtyList(myList)) 
		return NULL;		
	else  
		return myList->top;
}

int size(LINKEDLIST* myList) { //do chieu dau cua list
	if(isEmtyList(myList))
		return 0;
	int length = 0;
	for(NODE* n = myList->top; n != NULL; n = n->pre) 
		length++;
	return length; // tra ve do dai cua danh sach
}

void doPushing(LINKEDLIST* myList, int n) {
	NODE* p = creNode(n);
	push(myList, p);
}

int doPoping(LINKEDLIST* myList) {
	NODE* p = pop(myList);
	if (p == NULL)
		return 1;
	myList->top = p->pre;
	int data = p->data;
	free(p);
	return data;
}

void display(LINKEDLIST* myList) {
	//LINKEDLIST* temp = myList->top;
	//sai nha, neu dat la dia chi cua danh sach
	//thi khi thay doi dia chi danh sach thay doi, gay mat mat du lieu
	//CHi nên goi Node vi danh sach luon giu dia chi cua danh sach
	NODE* temp = myList->top;
	 //hien thi linked list da tao
	if(isEmtyList(myList)) //do dai bang 0 => khong co danh sach 
		printf("You dont have a list yet!");
	else {
		printf("Your list is:\n");
		while(temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->pre;
			//temp->top = temp->top->pre; //nguy hiem
			//Neu ban lam nhu vay thi con tro sau cung se tro NULL
			//va mat het du lieu
		}
		printf("NULL\n");
	}
}
#endif
