#ifndef EDITLINNKLIST
#define EDITLINNKLIST

#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h"

void informDeleteHeadNode(LINKLIST* myList) {
	removeFirst(myList);
	printf("\nyour act has just done!");
}

void informDeleteTailNode(LINKLIST* myList) {
	removeTail(myList);
	printf("\nyour act has just done!");
}

void informAddRandomeNode(LINKLIST* myList, NODE* p) {
	int x = 0;
	NODE* q = (NODE*) malloc(sizeof(NODE*));
	NODE* tmp = p;					
	printf("\nInput the integer you want: ");
	scanf("%d", &x); //luu y scandf k co khoang trang
	q = createNode(x);	
	int pos;
	printf("\nplease input your position: ");
	scanf("%d", &pos);
	
	tmp = myList->Head; //dua ve ban dau de do
	for(int i = 0; i < pos - 1; i++) 
	
		tmp = tmp->next;
	addNode(myList, tmp, q);
	printf("\nyour act has just done!");
}

void informAddFirst (LINKLIST* myList, NODE* p) {
	int n;
	printf("Input the integer in your list you want to add firt position: ");
	scanf("%d", &n); //luu y scandf k co khoang trang
	p = createNode(n);
	addHead(myList, p); //add vào dau 
	//addTail(myList, p);
	printf("\nyour act has just done!");
}

void informAddTail (LINKLIST* myList, NODE* p) {
	int n;
	printf("Input the integer in your list you want to add tail position: ");
	scanf("%d", &n); //luu y scandf k co khoang trang
	p = createNode(n);
	//addHead(myList, p); //add vào dau 
	addTail(myList, p);
	printf("\nyour act has just done!");
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
