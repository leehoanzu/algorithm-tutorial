#ifndef EDITLINNKLIST
#define EDITLINNKLIST

#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h"

void informAddFirst (LINKLIST* myList, NODE* p, int* length) { //dien gia tri NODE muon them vao dau danh sach
													// gui thòn tin NODE là hoi du thua
	int n; //gia tri cua NODE can tao
	printf("Input the integer in your list you want to add firt position: ");
	scanf("%d", &n); //luu y scandf k co khoang trang
	p = createNode(n); //dien gia tri n vao NODE p va dia chi tro tiep theo
	addHead(myList, p); //add vào dau 
	//addTail(myList, p);
	printf("\nyour act has just done!"); //thong bao
	(*length)++;
}

void informAddTail (LINKLIST* myList, NODE* p, int* length) { //tuong tu nhu add vao dau
	int n;
	printf("Input the integer in your list you want to add tail position: ");
	scanf("%d", &n); //luu y scandf k co khoang trang
	p = createNode(n);
	//addHead(myList, p); //add vào dau 
	addTail(myList, p);
	printf("\nyour act has just done!");
	(*length)++;
}

void informAddRandomeNode(LINKLIST* myList, NODE* p, int* length) { //add vao vi tri bat ki trong danh sach
	int x; //khai bao gia tri cua NODDE muon them vao
	NODE* q = (NODE*) malloc(sizeof(NODE*));
	NODE* tmp = p;					
	printf("\nInput the integer you want: ");
	scanf("%d", &x); //luu y scandf k co khoang trang
	q = createNode(x);	
	int pos; //vi tri muon add vao danh sach
	printf("\nplease input your position: ");
	scanf("%d", &pos);
	
	tmp = myList->Head; //dua ve ban dau de do
	if ((pos - 2) > *length | (pos - 1) < 0) // pos tru 2 vi tinh ca vi tri tail de add 
		printf("Sorry! Its out of bound\n");
	else if ((pos - 1) == 0)
		addHead(myList, q);
	else {
		for(int i = 0; i < (pos - 2); i++) 	//tru di 2 la vi NODE bat dau tu vi tri 0
											//nen ta tru di 1 de may hieu dung vi tri
											// tru lan 2 la vi ta chi can lay dia tri truoc NODE can them 
											//neu k tru t lay vi tri muon xoa va se them sai vi tri
			tmp = tmp->next;		
		addNode(myList, tmp, q); //them vao vi tri random 
		printf("\nyour act has just done!");
		(*length)++;
	}	
	//free(q);
	//free(tmp); xoa la sai nha
	//xoa se mat dia chi NODE sao ma in 
}

void informDeleteHeadNode(LINKLIST* myList, int* length) { //
	removeFirst(myList);
	printf("\nyour act has just done!");
	(*length)--;
}

void informDeleteTailNode(LINKLIST* myList, int* length) {
	removeTail(myList);
	printf("\nyour act has just done!");
	(*length)--;
}

void informDeleteRandomeNode(LINKLIST* myList, int* length) {
	int pos; //vi tri ma muon xoa
	NODE* q = myList->Head; //tao ra con tro tam muon xoa
	printf("Please input your position you want to remove: ");
	scanf("%d", &pos);
	
	if((pos - 1) > (*length) | (pos - 1) < 0) //tranh truong hop go tao lao
		printf("That is out of bound!\n");
	else if((pos - 1) == 0){
		removeFirst(myList);
		printf("\nYour act has just done!");
		(*length)--;	
	}
	else if ((pos - 1) == (*length) ) {
		removeTail(myList);
		printf("\nYour act has just done!");
		(*length)--;
	}
	else {
		for(int i = 0; i < (pos - 2); i++) //tru di 2 la vi NODE bat dau tu vi tri 0
											//nen ta tru di 1 de may hieu dung vi tri
											// tru lan 2 la vi ta chi can lay dia tri truoc NODE can xoa 
											//neu k tru t lay vi tri muon xoa va se xoa sai vi tri
			q = q->next;
		removeRandomNode(myList, q);
		printf("\nYour act has just done!");
		(*length)--;
	}		
}

void printList(LINKLIST* myList) {
	NODE* p;
	
	for(p = myList->Head; p != NULL; p = p->next) {
		if(p == myList->Tail) // m la thang cuoi cung cua danh sach roi
								//hoac co the su dung if(p->next == NULL) 
								//tai vi p->next cua NODE cuoi cung tro toi NULL
			printf("%d", p->data);		
		else
			printf("%d->", p->data);
	}
	
	free(p);	
}

#endif
