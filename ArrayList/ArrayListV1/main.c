#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct { //khoi tao 1 kieu du lieu su dung cho array list, danh sach dac,...
				//dung typedef la dinh dang lai kieu co san de kiey=u struct ngan hon khi goi
				//chu hok la vo mat khi khai bao struc arrayList arrList1 (qua dai)
				//thay vao do la typedef struct {} "Ten  muon thay the"
	
	int data;	//khai bao so phan tu trong mang mong muon
	int arr[MAX]; //khai bao mot mang co gia tri toi da hay con goi la mac dinh
					//khi khai bao so phan tu (data) thi data phai <= MAX, hong la vo mat
} ArrList;


void initArrayList (ArrList* a) { //cai dat mat dinh cho so phan tu ban dau
	a->data = 6;	
}

int isEmptyList (ArrList* list) { //ham khiem tra xem so phan tu hay danh sach co du lieu chua
	if (list->data == 0)			//du lieu == 0 nghia la chua co khai bao so phan tu
		return 1;
	return 0;
}

int isFullList (ArrList* list) { //ham kiem tra so phan tu yeu cau co full chua
								
	if (list->data >= MAX) //kiem tra so phan tu mong muon khai bao bang max 
		return 1;
	return 0;
}

void addHeadList (ArrList* list, int x) { //ta se them vao dau danh sach
	if (isFullList(list) == 1) //luon kiem tra co day hay chua moi cho them
		printf("It's full ");
	else {
		
		for (int i = list->data; i > 0; i--) {//doi vi tri sang trai 1 don vi
											//phai doi cuoi danh sach truoc neu k muon bi mat du lieu 
			list->arr[i] = list->arr[i - 1]; 
		}
		list->arr[0] = x;
		list->data++;
	}
	
}

void addTailList (ArrList* list, int x) { //ta se them vao dau danh sach
	if (isFullList(list) == 1) //luon kiem tra co day hay chua moi cho them
		printf("It's full ");
	else {
		list->arr[list->data] = x; 	
		list->data++;
	}
	
}

void addRandomList (ArrList* list, int adr, int x) { //them phan tu vao vi tri bat ki cua danh sach
													// b1 : 0 < x =< n phai luon kiem tra dieu kien tien quyet nay
													//b2: x muon them o dau hay cuoi k
													//b3: neu o vi tri k thi vi tri k + 1 doi sang phai
													//sau do k = x 
	if (isFullList(list) == 1) //luon kiem tra co day hay chua moi cho them
		printf("It's full ");
	else if (x >= 0 | x < list->data ) {
		if (adr == 0) 
			addHeadList(list, x);
		else if (adr == (list->data)) //neu bang n - 1 thi la them vao sau
			addTailList(list, x);
		else 
		{
			for (int i = list->data; i > adr - 1; i--) {//doi vi tri sang trai 1 don vi
											//phai doi cuoi danh sach truoc neu k muon bi mat du lieu 
			list->arr[i] = list->arr[i - 1]; 			
			}		
			list->arr[adr - 1] = x;
			list->data++;			
		}		
	}
	else
		printf("The value added is out of range");
}

int main(int argc, char *argv[]) {
	ArrList* list;
	list = malloc(sizeof (ArrList));
	//list = calloc(1, sizeof (ArrList)); //co the su dung de mac dinh
	initArrayList(list);
	printf("The first value in array list is %d\n", list->data);
	if (isEmptyList(list) == 1) //kiem tra danh sach da khai bao du lieuj nao chua
		printf("It's empty\n");
	else
		printf("It has a value\n");

	if (isFullList(list) == 1) //kiem tra danh sach da day chua ne
		printf("It's full!!!\n");
	else
		printf("It needs more to be filled full!\n");
	
	printf("Input the list, please!\n");
	for (int i = 0; i < list->data; i++) { //in ra cac danh sach ban dau
		scanf("%d", &(list->arr[i])); //scanf k co dau cach, neu k la bi loi
										//scanf("%d ", &a); la vo mat vi "%d " phai k co dau cach
										//khai bao dung la scanf("%d", &a);
	}
	
		
	printf("Before list\n");	
	for (int i = 0; i < list->data; i++) { //in ra cac danh sach ban dau
		printf("%d ", (list->arr[i]));
	}	
	addHeadList(list, 8);
	
	printf("\nAfter add Head list\n"); //them mot bien vao dau danh sach gai tri mong muon
									//luon can than vong lap for khi dich truyen i-- <=> i > 0
									//											i++ <=> i < n
	//printf("%d\n", list->data); kiem tra xem có tang kich thuoc mang len k	
	for (int i = 0; i < list->data; i++) { //in ra cac danh sach ban dau
		printf("%d ", (list->arr[i]));
	}
	
	printf("\nAfter add Tail list\n"); //them mot bien vao cuoi danh sach
	addTailList(list, 10);
	for (int i = 0; i < list->data; i++) { //in ra cac danh sach ban dau
		printf("%d ", (list->arr[i]));
	}
	
	printf("\nAfter add somewhere in list\n"); //them mot bien vao cuoi danh sach
	addRandomList(list, 5, 15);
	for (int i = 0; i < list->data; i++) { //in ra cac danh sach ban dau
		printf("%d ", (list->arr[i]));
	}
	free(list);
	
	return 0;
}
