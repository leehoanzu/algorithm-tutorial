#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <stdio.h>
#include <stdlib.h>

//Sap xep tang dan
void selectionSort(int *arr, int length) {
	int minPos;
	for(int i = 0; i < length - 1; i++) {
		int minPos = i;
		for(int j = i + 1; j < length; j++) 
			if(arr[minPos] > arr[j])
				minPos = j;	
	
	//Swap
	swapPos(arr, minPos, i);
	}
}

//Sap xep giam dan
/*	i = 0	1	3	3	
		20 	30	10 	40
			0	1	2	
	i = 0: -> maxPos = i = 0
		arr[maxPos] = 10	
		j = i + 1 = 1
		arr[1] = 30	> arr[maxPos]
		thay maxPos = 1 => vòng lap cho den khi tim duoc maxPos,
		o day maxPos = 3	
		swap: arr[0] vs arr[maxpos]
*/
void selectionSortV2(int *arr, int length) {
	int maxPos;
	for(int i = 0; i < length - 1; i++) {
		int maxPos = i;
		for(int j = i + 1; j < length; j++) 
			if(arr[maxPos] < arr[j])
				maxPos = j;	
	
	//Swap
	swapPos(arr, maxPos, i);
	}
}

void swapPos(int *arr, int minPos, int defPos) {
	if(minPos != defPos) {
			int tmp = arr[minPos];
			arr[minPos] = arr[defPos];
			arr[defPos] = tmp;
		}
}


#endif
