#ifndef RECURSION
#define RECURSION


#include <stdio.h>
#include <stdlib.h>
#include "StackManagement.h"

//tinh giai thua
int calFactorial(int n) {
	if(n == 0 || n == 1)	
		return 1;
		
	int tmp = 1;
	//Khoi tao danh sach cac phan tu trong giai thua
	LINKEDLIST* myList = (LINKEDLIST*) malloc(sizeof(LINKEDLIST));
	initLinkedList(myList);
	//day vao stack
	for(int i = n; i != 0; i--)
		doPushing(myList, i);
		
	for(int i = n; i != 0; i--) 
		tmp *= doPoping(myList);
	
	return tmp;
}

#endif
