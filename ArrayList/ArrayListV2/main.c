#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct { 
	
	int count;	
	int arr[MAX]; 
} ArrList;


void initArrayList (ArrList* a) { 
	a->count = 6;	
}

int isEmptyList (ArrList* list) { 
	if (list->count == -1)			
		return 1;
	return 0;
}

int isFullList (ArrList* list) { //ham kiem tra so phan tu yeu cau co full chua
								
	if (list->count >= MAX) //kiem tra so phan tu mong muon khai bao bang max 
		return 1;
	return 0;
}


void RemoveFirst(ArrList* list) { //xoa 1 phan tu dau tien trong mang
								  //khi nay ta dich man qua phai va giam so phan tu mang xuong 1 don vi
								
	if(isEmptyList(list) == 1)
		printf("\nIt's empty. We can revmove the element\n");
	else {
		for (int i = 0; i < list->count; i++) 
		list->arr[i] = list->arr[i + 1];
		list->count--;
	}							  
	
}

void RenoveRandomList(ArrList* list, int k) {
	if (k < 0 | k > list->count - 1)
		printf("The position you wanna remove is not correct");
	else {
		for (int i = k - 1; i < list->count; i++) { //k -1 : co nghia la vi tri thu 5 theo mat nguoi nhin
													///nhung trong mang bat dau tu 0 nen vi tri do trong mang la 4 hay k - 1
			list->arr[i] = list->arr[i + 1]; 
		}
		list->count--;
	}
	
}

void Removetail (ArrList* list) { //ta chi can giam so luong element xuong va k can quan tam bien tail
									//no tu rot ra va troi lac o dau do, co the nam im k di dau ca
	if(isEmptyList(list))
		printf("\nIt's empty. We can revmove the element\n");
	else 
		list->count--;
				
}

int main(int argc, char *argv[]) {
	ArrList* list;
	list = malloc(2*sizeof (ArrList));
	//list = calloc(1, sizeof (ArrList)); //co the su dung de mac dinh
	initArrayList(&list[0]);
	printf("The first value in array list V2 is %d\n", list->count);
	if (isEmptyList(list) == 1) //kiem tra danh sach da khai bao du lieuj nao chua
		printf("It's empty\n");
	else
		printf("It has a value\n");

	if (isFullList(list) == 1) //kiem tra danh sach da day chua ne
		printf("It's full!!!\n");
	else
		printf("It needs more to be filled full!\n");
	//printf("%d\n", (list + 0)->arr[i]); in ra 1 giá tri cua mang 
	printf("Input the 1st list, please!\n");
	for (int i = 0; i < (list + 0 )->count; i++) { 
		scanf("%d", &((list + 0 )->arr[i])); 
	}
	
		
	printf("Before 1st list\n");	
	for (int i = 0; i < (list + 0 )->count; i++) { //in ra cac danh sach ban dau
		printf("%d ", ((list + 0 )->arr[i]));
	}	
	
	
	RemoveFirst(list);
	
	printf("\nAfter remove  Head list\n"); 
	for (int i = 0; i < list->count; i++) { //in ra cac danh sach  sau khi xoa 1 mang dau ki tu
		printf("%d ", (list->arr[i]));
	}
	
	Removetail(list);
	
	printf("\nAfter remove  Tail list\n"); 
	for (int i = 0; i < list->count; i++) { //in ra cac danh sach  sau khi xoa 1 mang cuoi cua ki tu
		printf("%d ", (list->arr[i]));
	}
	
	RenoveRandomList(list, 3);
	printf("\nAfter remove Randome list\n");
	for (int i = 0; i < (list + 0 )->count; i++) {
		printf("%d ", (list + 0 )->arr[i]);
	}

	free(list);
	return 0;
	
}
