#ifndef INFORMLINKLIST
#define INFORMLINKLIST

#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h"

void informAddHead(CIRLINKLIST* myList, int* length) { //length: do dai cua mang ne
	int data;
	NODE* p;
	printf("\nPlease input your value wanting to input in the head: ");
	scanf("%d", &data);
	p = creNode(myList, data);
	insrtHeadNode(myList, p);
	(*length)++;
	printf("Your act has just done\n");
}

void informAddTail(CIRLINKLIST* myList, int* length) {
	int data;
	NODE* p;
	printf("\nPlease input your value wanting to input in the tail: ");
	scanf("%d", &data);
	p = creNode(myList, data);
	insrtTailNode(myList, p);
	(*length)++;
	printf("Your act has just done\n");	
}

void informAddRandomeNode(CIRLINKLIST* myList, int* length) {
	int data;
	unsigned int pos;
	NODE* p;
	NODE* tmp = myList->head; //phai dua no ve vi tri dau
	printf("\nPlease input your NODE' value: ");
	scanf("%d", &data); 
	p = creNode(myList, data); //nhap data
	
	if((*length) == -1) { //neu chua co danh sach thi k cho phep nhap vi tri
						//vi dieu do se eat vo li
		printf("\nWatch out! you dont have a list yet\n");
		printf("you will be inserted default!\n");
		insrtHeadNode(myList, p);
		(*length)++;
		printf("Your act has just done!\n");
		
	}	
	else {
		printf("\nPlease choose your position you want to insert in the list: ");
		scanf("%d", &pos); //nhap vi tri
	
		
		if (pos < 0 || pos > (*length + 2)) { // pos tru 2 la vi 1. length bat dau dem tu 0
											// 2. la se co truong hop in chen vi tri cuoi  (sau vi tri length 1 don vi)
											//so sanh 2 so am la toang day
			//printf("%d\n", pos - 2);
			printf("Opps! you choose out of bound\n");
			//printf("Your act has just done!\n");
			
		}
		else if (pos == 1) { //neu nhap vi tri dau tien khi da co danh sach => chen vi tri dau
			insrtHeadNode(myList, p);
			(*length)++;
			printf("Your act has just done!\n");
			
		}
		else if ((pos - 2) == (*length)) {
			insrtTailNode(myList, p);
			(*length)++;
			printf("Your act has just done!\n");
			
		}
		else {
			for(int i = 0; i < (pos - 2); i++)  /// pos tru 2 la vi 1 i bat dau dem tu 0
											// 2. ta lay NODE o vi tri truoc vi tri can chen
				tmp = tmp->next;
			insrtRandomeNode(myList, p, tmp);
			(*length)++;
			printf("Your act has just done!\n");
			
		}
	}
	
}

void informdelFirstList(CIRLINKLIST* myList, int* length) {	
	if (myList->head == NULL)
		printf("\nYou dont have a list yet!\n");
	else {
		delFirstList(myList, length);
		(*length)--;
		printf("\nYour acr has just done!\n");	
	}	
}

void informdelTailList(CIRLINKLIST* myList, int* length) {
	NODE* tmp; 
	if (myList->head == NULL)
		printf("\nYou dont have a list yet!\n");
	else {
		for(tmp = myList->head; tmp->next != myList->tail; tmp = tmp->next);
		delTailList(myList, tmp, length);
		(*length)--;
		printf("\nYour acr has just done!\n");	
	}
}

void informdeRandomeList(CIRLINKLIST* myList, int* length) {
	NODE* tmp = myList->head; 
	unsigned int pos;
	printf("\nPlease choose your position you want to insert in the list: ");
	scanf("%d", &pos); //nhap vi tri
	if (myList->head == NULL)
		printf("\nYou dont have a list yet!\n");
	else if (pos < 0 || pos > (*length + 1))  
		printf("Opps! you choose out of bound\n");
	else if (pos == 1) 
		informdelFirstList(myList, length);
	else if (pos - 1 == *length)
		informdelTailList(myList, length);	
	else {
		for(int i = 0; i < pos - 2; i++)
		tmp = tmp->next;
		delRandList(myList, tmp, length);
		(*length)--;
		printf("\nYour acr has just done!\n");	
	}
}

void printList(CIRLINKLIST* myList, int* length) {
	NODE* temp;
//	printf("%d\n", (*length));
	if(isEmpty(myList))
		printf("You dont have a list yet");
	else {
		for(temp = myList->head; temp->next != myList->head; temp = temp->next) {
//			if (temp == myList->tail)
//				printf("%d\n", temp->data); //sai nha, vi chua kt la no da tat lai roi
//			else
			printf("%d->", temp->data);
		}
//		printf("%d->%d\n", temp->data, temp->next->data);
//		printf("%d", 4);
		printf("%d\n", temp->next->data);
	}
}

#endif
