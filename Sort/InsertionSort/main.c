#include <stdio.h>
#include <stdlib.h>
#include "InsertionSort.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define lengthArr(arr) sizeof(arr)/sizeof(arr[0])

void fillArr(int *arr, int length);
void printArr(int *arr, int length);

int main(int argc, char *argv[]) {
	int arr[10];
	//printf("Check length of arr: %d\n", lengthArr(arr)); //check length
	
	printf("Please fill your array what length of array you want\n");
    fillArr(arr, lengthArr(arr));

    printf("Original array: ");
    printArr(arr, lengthArr(arr));
    
    //sort
    insertionSort(arr, lengthArr(arr));
    
    //array afters sorting
    printf("Sorting array ascending: ");
    printArr(arr, lengthArr(arr));
    
    insertionSortV2(arr, lengthArr(arr));
    
    //array afters sorting
    printf("Sorting array descending: ");
    printArr(arr, lengthArr(arr));
	system("pause");
	return 0;
}

//fill array
void fillArr(int * arr, int length) {
	// sizeof(arr) will give you the size of the pointer, not the size of the array.
	//int length = lengthArr(arr); -> this is error if you use this way

//	or if you want to fill the size
//	printf("Input your lenth of array\n");
//	scanf("%d", &length);

	for(int i = 0; i < length; i++)
		scanf("%d", &arr[i]);
}

//Print list agrument in array
void printArr(int * arr, int length) {
	for(int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


