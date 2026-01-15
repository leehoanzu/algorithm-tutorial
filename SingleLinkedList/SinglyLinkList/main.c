#include <stdio.h>
#include <stdlib.h>
#include "Precessor.h" //noi day co cach tao ra cac node va danh sách
#include "Menu.h"
#include "EditLinklist.h"
//chuong trinh tao ra singly link list
//dau tien la tao node -> tao ra danh sach su dung node -> them bot ( giong nhu Array list)


void doIt (LINKLIST* myList, NODE* p, int n); 

int main(int argc, char *argv[]) {
	
//	int n, a = 0;
//	int length;
	NODE* p = (NODE*) malloc(sizeof(NODE*));
	LINKLIST* myList = (LINKLIST*) malloc(sizeof(LINKLIST*));
	initLinkList(myList);
	
	int n;
	while (n != 7) {
		menu();
		printf("input: ");
		scanf("%d", &n);
		doIt(myList, p, n);		
	}
	return 0;
}

void doIt (LINKLIST* myList, NODE* p, int n) {
	
	switch (n) {
		case 1:
			informAddFirst(myList, p);
			break;
		case 2:
			informAddTail(myList, p);
			break;
		case 3:
			informAddRandomeNode(myList, p);			
			//free(tmp); //can than de sai
			break;
			
		case 4:
			removeFirst(myList);			
			printf("\nYour list after removing Head\n");
			printList(myList); //in danh sach sau khi xoa
			break;	
		case 5:
			informDeleteTailNode(myList);
			printf("\nYour list after removing tail\n");
			printList(myList); //in danh sach sau khi xoa			
			break;
		case 6:
			printList(myList);
			printf("\n");
			break;	
		case 7: 
			printf("bye bye!");
			break;
		default :
			break;
	
	}
}

