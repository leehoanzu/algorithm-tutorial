//khi muon tao 1 file header thuong thi ta luu nó trong cung 1 thu muc voi main.c
//b1: ta chi can tao new source
//b2: define du lieu
//b3: luu vao trong cung 1 thu muc va tao ra nhu thu vien
//trong vi du ve precessor nay ta vi du cach tao ra linklist

#ifndef PRECESSOR
#define PRECESSOR

#include <stdio.h>
#include <stdlib.h>


typedef struct NODE { //tao cac nut
						//de de goi ten ta nen su dung typedef de dinh nghia lai ten
	int data;  //data luu tru so (co the them char, double, ...)
	struct NODE* next; //noi duoi theo sau la mot cai node moi
				//duoi co the tro toi mot cai duoi (tail) khac hoac la NULL (am chi ket thuc 1 singly link list)
	
} NODE;

typedef struct LINKLIST { //trong mot singly link list can co mot vi tri dau va duoi
							//dau (Head) de su dung va truy cap bat dau tu do den cac NODE tiep theo
							//va 1 duoi (Tail) de thong bao danh sach da het, ngung truy cap
	NODE* Head;  //NODE dau tien trong danh sach
	NODE* Tail;	 //NODE cuoi cung trong danh sach
} LINKLIST;

void initLinkList (LINKLIST* myList) {
	myList->Head = myList->Tail = NULL;
}

NODE* createNode (int x) { //tao gia tri trong NODE
	NODE* p = (NODE*) malloc(sizeof(NODE*));
	if (p == NULL) {
		printf("This is error, your memory doesn't have enough space to add pointer'ram'");
		return NULL;
	}		
	else {
		p->data = x;
		p->next = NULL; //neu next k theo thi se mac dinh la null
		return p;
	}	
}

int isEmptyList (LINKLIST* myList) {
	if (myList->Head == NULL) //kiem tra xem con tro dau tien co chua du lieu k
								//neu ko co thi chac chan la danh sach rong
								//vi tri dau ma k co ai thi phai la rong
		return 1; // chinh xac, day la rong
	return 0; //m co du lieu, m la mot danh sach nhung chua biet m co cai gi hoy
}

void addHead (LINKLIST* myList, NODE* p) { //them phan tu vao dau danh sach
												//theo kieu FIFO (first in first out), so cang nhap sau cung thi dung dau
	if (isEmptyList(myList)) { //kiem tra danh sach co rong hay k
								//neu rong thi day la phan tu dau tien, vay nen tay ke tiep chi can tro vao duoi la duoc
		p->next = myList->Tail; //k can gan cung duoc vi mac dinh khi k gan la NULL
		myList->Head = myList->Tail = p;								
	}
	else { //neu da co mot danh sach khac thi con tro next cua tro moi se chi vao node truoc do
		p->next = myList->Head; //viec lam dau tien
		myList->Head = p;
		
	}
}

void addTail (LINKLIST* myList, NODE* p) { //them node vao phan tu cuoi hay no se la phan tu duoi 
	if (isEmptyList(myList)) { //kiem tra danh sach rong hay k
		myList->Head = myList->Tail = p;
	}
	else {
		myList->Tail->next = p; //Tail-> next tro dia chi cua node moi
								//day la viec can lam dau tien
		myList->Tail = p;
	}
}

void addNode(LINKLIST* myList, NODE* p, NODE* q) { //tao ra 1 node bat ki ow vi tri x
												//kiem tra xem x co phai vi tri tail k
							//NODE cu	//NODE can them
	q->next = p->next;
	p->next = q; //them vao sau NODE cu
	if (myList->Tail == p) //neu vi tri nam o dau thi dung ham addTail co san
		addTail(myList, q); //luu y la add NODE q, node moi tao nha
//	if (myList->Head == p)
//		addHead(myList, q);											
} 

void removeFirst(LINKLIST* myList) { //huy 1 phan tu dau ra khoi danh sach
	//viec dau tien khi xoa mot phan tu dau la kiem tra xem danh sach co bao nhieu phan tu hay la rong
	//1. neu rong thi bao loi ( chui error roi nha!!!)
	//2. neu khong rong ma chi co 1 phan tu thi ca Head va Tail deu chi NULL
	//3. neu > 1 phan tu thi gan dia chi 2 vao con tro Head
	NODE* p = myList->Head; //dua di chi truoc khi xoa di
	if (isEmptyList(myList))
		printf("Sorry! you didnt have a list yet."); //chui khi chua co thanh vien ma doi xoa
	else if (myList->Head->next == myList->Tail)
		myList->Head = myList->Tail = NULL; //chi co 1 thanh vien, xoa tro thanh rong!
	else
		myList->Head = myList->Head->next;	// thi con tro Head tro toi vi tri tiep thoe
											//neu so luong thanh vien lon hon 1
	free(p); //xoa vi tri ban dau cua Head bo lai
			//vd nhu 1->2->3->4->5, sau khi xoa di thi khi ra thay dc 2->3->4->5
			//nhung con NODE dau tien van con dau do trong ram gay ton bo nho
			//ta da gan dia chi cua NODE 1 o dong 92
			//gio chi can toi dia chi do va xoa la ok
}

void removeTail(LINKLIST* myList) { //huy 1 phan tu duoi ra khoi danh sach
	//viec dau tien khi xoa mot phan tu dau la kiem tra xem danh sach co bao nhieu phan tu hay la rong
	//1. neu rong thi bao loi ( chui error roi nha!!!)
	//2. neu khong rong ma chi co 1 phan tu thi ca Head va Tail deu chi NULL
	//3. neu > 1 phan tu thi 
							//a. gan comn tro p la null ( p la con tro dung truoc Tail)
							//b. doi lai Tail = p;
	NODE* x = myList->Tail; //dua vi tri cuoi khi xoa muon xoa
	if (isEmptyList(myList))
		printf("Sorry! you didnt have a list yet."); //chui khi chua co thanh vien ma doi xoa
	else if (myList->Head->next == myList->Tail)
		myList->Head = myList->Tail = NULL; //chi co 1 thanh vien, xoa tro thanh rong!
	else {
//		do {
//			p = p->next;
//		} while (p->next != myList->Tail);
		NODE* p;
		for(p = myList->Head; p->next != myList->Tail; p = p->next);
		p->next = NULL;
		myList->Tail = p;	
	}
	//free(p); //mat dia chi roi sao ma gan
	free(x); //xoa di vi vi tri Tail da thay doi
}

void removeRandomNode (LINKLIST* myList, NODE* q) { //xoa 1 vi tri bat ki
													//gui danh sach va vi tri NODE truoc vi tri NODE can xoa
													//ham chi lam hanh dong xoa, con them cac yeu cau khac thi o thu vien 
													//EditLinklist
	NODE* x = q->next; //luu dia chi NODE can xoa
						//de sau khi xoa thi ta giai phong bo nho NODE o dong 143, tiet kiem bo nho
	if (isEmptyList(myList))  //kiem tra xem co rong k
								//rong ma xoa la tam bay
		printf("sorry! you dont have a list yet.\n");
	else
		q->next = x->next; //xoa thi doi con tro next sang vi tri ke
							//ta da lay dc dia chi, nen sau khi x bi xoa thi ta van k bi anh huong
	free(x);
}

#endif
