#ifndef EDITLINNKLIST
#define EDITLINNKLIST

#include <stdio.h>
#include <stdlib.h>
void informDeleteHeadNode(LINKLIST* myList) {
	removeFirst(myList);
	printf("\nyour act has just done!");
}

void informDeleteTailNode(LINKLIST* myList) {
	removeTail(myList);
	printf("\nyour act has just done!");
}

#endif
