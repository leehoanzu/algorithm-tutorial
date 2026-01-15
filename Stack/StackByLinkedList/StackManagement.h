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

NODE* creNode(int data) { //tao node
	NODE* Node = (NODE*) malloc(sizeof(NODE)); //khoi tao 1 vung khong gian cho Node trong Heap
	Node->data = data; //gan gia tri data cho node
	Node->pre = NULL;
//	Node->pre = prePtr; //gan dia tri cua Node truoc do
//						//vi day la stack nap du lieu theo kieu FIFO
	return Node;
}
			
static void initLinkedList(LINKEDLIST* myList) {
	myList->top = NULL; //luon khoi tao gia tri ban dau cua danh sach o vi tri NULL
						//O vi tri 0x00, neu k se k xac dinh duoc vi tri ban dau va gay loi
}

static int isEmtyList(LINKEDLIST* myList) { //kiem tra danh sach co rong 
	return myList->top == NULL ? 1 : 0; //tra ve 1 neu la NULL va nguoc lai
}

static int push(LINKEDLIST* myList, NODE* nodePtr) { //them data vao dau danh sach
	if(isEmtyList(myList)) { //neu la gia tri tao moi thi con tro pre la NULL
		myList->top = nodePtr; //dau tien thi top la gia tri nodePtr
		nodePtr->pre = NULL; //dau tien thi con tro pre luon la NULL
		//return 1; //phat co da lam xong va thoat ham
	}
	else {
		nodePtr->pre = myList->top; //chen vao vi tri dau thi sau no se la thang top cu 
									//chua thay doi
		myList->top = nodePtr;
	}
	return 1; //phat co da xong
}

static NODE* pop(LINKEDLIST* myList) { //xoa data o dau danh sach va hien thi ra
	if(isEmtyList(myList)) 
		return NULL;		
	else  
		return myList->top;
}


void doPush(LINKEDLIST* myList) { //thuc hien day gia tri vao dau danh sach
								//va hien thi thong bao
	int data;
	printf("Please input your data of stack: \n");
	scanf("%d", &data);
	NODE* nodePtr = creNode(data);
	if (push(myList, nodePtr))
		//printf("Your value is %d\n", myList->top->data);
		printf("Your act has just done!\n");
}


void doPop(LINKEDLIST* myList) { //tien hanh xoa 1 Node va thong bao cho user
	if(pop(myList) == NULL)
		printf("You dont have a list yet\n");
	else {
		NODE* temp = pop(myList); //tra ve dia chi cua NODE dau tien
		int data = temp->data;
		myList->top = temp->pre; //dua con tro top lui ve 1 dia chi (dia chi trc do)
		temp->pre = NULL; //xoa con tro pre o Node cu
		free(temp); //giai phong bo nho can xoa
		printf("You have just release the node has value: %d\n", data);
	}
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
