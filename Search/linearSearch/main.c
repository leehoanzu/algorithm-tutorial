#include<stdio.h>
#include <stdlib.h>
// Boolean data type
#include <stdbool.h>

//Ðây là bài linear search trong tutorial câu trúc du lieu va giai thuât
//Su dung key va vong lap de tim duoc so co san trong mang da cho truoc
//Co ban la neu a[i] = key thi tim thay, neu chay het vong for ma k thay thi key sai
//Toc do O(n)

bool isFoundLinearSearch(int* arr, int key, int length);
int arrLength (int* arr);

int main (void) {
	int arr[5] = {10, 20, 30, 40, 50};
	int key;
	int length = arrLength(arr);
	
	//printf("Your length of array is: %d\n", length);
	printf("Your array is: ");
	for(int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\nInput your key wants to find: ");
	scanf("%d", &key);
	if(isFoundLinearSearch(arr, key, length))
		printf("\nKey is found\n");
	else
		printf("Key is not found\n");
	puts("Waiting to press random key for quit...");
//	getch(); //cho dung man hinh terminal
	return 0;
}


bool isFoundLinearSearch(int* arr, int key, int length) {
	if (arr == NULL || length <= 0) {
        return false; // Mang khong hop ly hoac co chieu dai khong hop ly
    }
	for (int i = 0; i < length; i++)
		if(key == arr[i]) 
			return true; //Found
	return false;
}

/**Count length of arry use loop*/
int arrLength(int* arr) {
	int length = 0;
	for(int* i = arr; *i != '\0'; i++) 
		length++;
	return length;
}
