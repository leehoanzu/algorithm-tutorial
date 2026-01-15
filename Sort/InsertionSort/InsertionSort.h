#ifndef INSECTION_SORT
#define INSECTION_SORT

#include <stdio.h>
#include <stdlib.h>

//Sap xep tang dan
void insertionSort(int *arr, int length) {
	int j = 0;
	for(int i = 1; i < length; i++) {
		int temp = arr[i];
		for(j = i; j > 0 && temp < arr[j - 1]; j--) 
			arr[j] = arr[j - 1];					
		arr[j] = temp;
	}
}

//Sap xep giam dan
/*		10 	20 	30 	40
			0	1	2	3
	j = 1:
		temp = arr[j] = 20
		- arr[j] = 20 > 10 
			=> if (arr[j] > arr[j - 1]) <=> arr[j] = arr[j - 1] (doi vi tri gia tri truoc do)	
			ket qua:  20 10 30 40
		
	j = 2: 
		temp = arr[j] = 30
		- arr[j] = 30 > 10 
			=> if (arr[j] > arr[j - 1]) <=> arr[j] = arr[j - 1] (doi vi tri gia tri truoc do)	
			ket qua:  20 30 10 40
			
		- arr[j] = 30 > 20 
			=> if (arr[j] > arr[j - 1]) <=> arr[j] = arr[j - 1] (doi vi tri gia tri truoc do)	
			ket qua:  20 20 10 40
			
		Luc nay j = 0 => arr[j] = temp	
			ket qua: 30 20 10 40					
*/
void insertionSortV2(int *arr, int length) {
	int j = 0;
	
	for(int i = 1; i < length; i++) {
		int temp = arr[i];
		for(j = i; j > 0 && temp > arr[j - 1]; j--) {
			arr[j] = arr[j - 1];
		}	
		arr[j] = temp;					
	}
}
#endif
