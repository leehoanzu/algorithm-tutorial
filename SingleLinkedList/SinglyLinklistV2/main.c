#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h" //noi day co cach tao ra cac node va danh sách
#include "Menu.h"
#include "EditLinklist.h"
//chuong trinh tao ra singly link list
//dau tien la tao node -> tao ra danh sach su dung node -> them bot ( giong nhu Array list)


int main(int argc, char *argv[]) {
	
	NODE* p = (NODE*) malloc(sizeof(NODE*));
	LINKLIST* myList = (LINKLIST*) malloc(sizeof(LINKLIST*));
	initLinkList(myList);
	int n;
	unsigned int length = -1; //chieu dai cua cai list minh tao ra
								//vi tri dau tien se la 0
								//nham tuong thich giong voi mang
					//moi lan tao hay xoa deu se ++ hoac --

	while (n != 8) {
		menu();
		printf("input: ");
		scanf("%d", &n);
		doIt(myList, p, n, &length);		
	}
	return 0;
}



