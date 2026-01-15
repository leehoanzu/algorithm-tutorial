#ifndef	BUBBLE_SORT
#define	BUBBLE_SORT

#include <stdio.h>
#include <stdlib.h>

//This is bubble sort
void bubbleSort(int *a, int length) {
	for(int i = 0; i < length - 1; i++)
		for(int j = 0; j < length - 1 -i; j++) 
			if(a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		
}

#endif
