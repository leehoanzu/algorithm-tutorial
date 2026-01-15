#ifndef Queue
#define Queue

/*----------------------------------------------------------------------------
 In this section i will provide you the information about Enqueue & Dequeue
 Day la 1 dang cua FIFO (First in First out)
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data; //du lieu cua node
	struct Node* next; //vi tri cua node tiep theo
} NODE;

typedef struct {
	NODE* front; //dia chi cua node dau tien
	NODE* rear; //dia chi cua node cuoi cung trong queue
} LINKEDLIST;

void initList(LINKEDLIST* myList) { //Cai dat dau tien khi khoi tao danh sach
	myList->front = myList->rear = NULL;
	//Ban dau gan dia chi cua danh sach la null
	//neu khong danh sach se lo lung va gay ra loi
}

static int isEmptyList(LINKEDLIST* myList) { //kiem tra danh sach da dc imple chua
	return myList->front == NULL ? 1 : 0;
	//Tra ve 1 neu la danh sach trong
}

static NODE* creNode(int data) {//tao node cho danh sach
	NODE* Node = (NODE*) malloc(sizeof(NODE)); //khoi tao vung nho heap
	Node->data = data; //them du lieu vao Node moi tao
	Node->next = NULL; // dia chi next se la null
	return Node; //tra ve vung dia chi da tao
}

static int enQueue(LINKEDLIST* myList, NODE* ptr) {
	//tao moi mot du lieu vao hang doi
	if(isEmptyList(myList)) //neu la vi tri dau thi rear va front cung chi mot doi tuong
		myList->front = myList->rear = ptr; 
	else { //Neu da co it nhat 1 ele
		myList->rear->next = ptr; //dia chi con tro next cua node do
								//se tro den con tro moi tao tiep theo
		myList->rear = ptr; //gan dia chi rear la con tro moiw tao
	}
	return 1; //co bao hoan thanh
}

void deQueue(LINKEDLIST* myList) { //xoa di phan tu cuoi
	if(isEmptyList(myList))
		printf("Sorry! You need have a queue first.\n");
	else {
		NODE* temp = myList->front; //2 chang tro 1 nang
		myList->front = temp->next; //dua node front lui ve 1 node
		temp->next = NULL; //xoa di dia chi luu tru o vi tri can xoa
		printf("You have realse value %d out of queue.\n", temp->data);
		free(temp); //giai phong bo nho
	}
}

void doEnQueue(LINKEDLIST* myList) {
	int data; //tao du lieu can them vao
	printf("Please input your value: ");
	scanf("%d", &data); //dua vao du lieu data tu ban phim
	NODE* ptr = creNode(data); //tao 1 cvung nho Node
	if(enQueue(myList, ptr)) //doi khi them xong
		printf("\nYour act has just done!\n"); //thong bao khi hoan thanh
}

void display(LINKEDLIST* myList) {
	if(isEmptyList(myList))
		printf("You dont have a queue before.\n");
	else {
		NODE* temp = myList->front; //tao vung nho tam luu dia chi dau tien
									//cua danh sach
		printf("This is your queue: \n");
		while(temp != NULL) {
			printf("%d -> ", temp->data); //in ra gia tri
			temp = temp->next; // tro toi vi tri tiep theo
		}			
		printf("NULL\n"); //in ki hieu null va xuong dong
	}
}

#endif

