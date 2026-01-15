#ifndef INFORMLINKLIST
#define INFORMLINKLIST

#include <stdio.h>
#include <stdlib.h>

#include "Precessor.h"

void informInsrtHeadNode(DOUBLINKLIST* myList, int* length) {
	int data;
	printf("Please input data: ");
	scanf("%d", &data); //nhap vao gia tri mong muon
	printf("\n"); //xuong dong cho cau lenh tiep theo
	NODE* p = creNode(myList, data); //hung dia chi da tao ra NODE
	insrtHeadNode(myList, p);	//chen vao dau dia chi cua danh sach
	printf("your act has just done!\n");
	(*length)++; //tang do dai cua mang	
}

void informInsrtTailNode(DOUBLINKLIST* myList, int* length) {
	int data;
	printf("Please input data: ");
	scanf("%d", &data); //nhap vao gia tri mong muon
	printf("\n"); //xuong dong cho cau lenh tiep theo
	NODE* p = creNode(myList, data); //hung dia chi da tao ra NODE
	insrtTailNode(myList, p);	//chen vao dau dia chi cua danh sach
	printf("your act has just done!\n");
	(*length)++; //tang do dai cua mang
}

void informInsrtRandNode(DOUBLINKLIST* myList, int* length) {
	int data, pos; //pos la vi tri p muon chen tu giao dien
	NODE* q = myList->head;
	printf("Please input data: ");
	scanf("%d", &data); //nhap vao gia tri mong muon
	NODE* p = creNode(myList, data); //se bi tao ra qua nhieu
	printf("\nPlease input your pos: ");
	scanf("%d", &pos);
	printf("\n");
	if (pos < 1 | pos > (*length) + 2)
		printf("Your position is out of bound!\n");
	else if (pos == 1) {
		insrtHeadNode(myList, p);
		(*length)++;
	}		
	else if (pos == (*length) + 2) {
		insrtTailNode(myList, p);
		(*length)++;
	}		
	else {
		for (int i = 0; i < pos - 1; i++)
			q = q->next;
		insrtRandomNode(myList, q, p);
		(*length)++; //phai dong ngoac nhe
		printf("Your act has just done!\n");
	}
}

void informDelHeadNode(DOUBLINKLIST* myList, int* length) {
	delHeadNode(myList);
	if(!isEmpty(myList)) {
		//printf()
		printf("your act has just done!\n");
		(*length)--;
	}
}

void informDelTailNode(DOUBLINKLIST* myList, int* length) {
	delTailNode(myList);
	if(!isEmpty(myList)) {
		printf("Your action has just done!\n");
		(*length)--;
	}
}

void printList(DOUBLINKLIST* myList) {
	NODE* p = myList->head;
	if (isEmpty(myList))
		printf("You didnt have a list yet!\n");
	else {
		printf("%d->", p->data); //k can phai xet dieu kien qua nhieu
		for(p = p->next; p != myList->tail; p = p->next) //nho chu y dk phai la p != myList->tail
			printf("<-%d->", p->data);
		printf("<-%d\n", p->data);		
	}
}

#endif
