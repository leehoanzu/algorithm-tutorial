#include <stdio.h>
#include <stdlib.h>
// Boolean data type
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Count the length of array
#define arraylength(arr) sizeof(arr)/sizeof(arr[0])

int isFoundBinarySearch(int* arr, int low, int high, int key);
int arrLength(int* arr);

int main(int argc, char *argv[]) {
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int low = 0;
	int high = arraylength(arr);
	int key = 90;
	int pos = isFoundBinarySearch(arr, low, high, key);
	printf("Your array length is %d\n", high);
	//printf("Your array length is %d\n", arrLength(arr));
	
	printf("This is a list of array: \n");
	for(int i = 0; i < high; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	if(pos != -1)
		printf("Your key %d has found at %d\n", key, pos + 1);
	else
		printf("Your key is out of bound array\n");
	
	
	//getch();
	system("pause");
	return 0;
}


/**Count length of arry use loop*/
int arrLength(int* arr) {
	int length = 0;
	for(int* i = arr; *i != '\0'; i++) 
		length++;
	return length;
}

//Flag if it's found
int isFoundBinarySearch(int* arr, int low, int high, int key) {
	while (low <= high) {
		int mid = (high + low)/2;
		
		if(key == arr[mid]) 
			return mid;
		else if(key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;		
	}
	return -1;	
}


