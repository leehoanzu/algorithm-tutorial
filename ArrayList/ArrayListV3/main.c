#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 100

typedef struct {
	int n; //so mang muon tao
	int a[MAX]; //khai bao mang ban dau
}arrayList;

int sortArray(int* a, int n);
int sortArrayV2(int* a, int n);

int main(int argc, char *argv[]) {
	arrayList* p = malloc(sizeof(arrayList));
	printf("Khai bao so mang muon tao: ");
	scanf("%d", &p->n);
//	printf("%d", p->n);
	printf("Dien vao so mang: ");
	for(int i = 0; i < p->n; i++)
		scanf("%d", &p->a[i]);
	
	printf("\nMang truoc khi sap xep: \n");
	for(int i = 0; i < p->n; i++)
		printf("%d ", (p->a)[i]);	
		
	printf("\nMang sau khi sap xep:\n");
//	sortArray(p->a, p->n);
	sortArrayV2(p->a, p->n);
	for(int i = 0; i < p->n; i++)
		printf("%d ", (p->a)[i]);
	return 0;
}

int sortArrayV2(int* a, int n) { //bubble sort ascending
//	int n = sizeof(a)/sizeof(int);
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if (a[j] < a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}				
		}
	}
}

int sortArray(int* a, int n) { //interchange sort
//	int n = sizeof(a)/sizeof(int);
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if (a[i] < a[j]){
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}				
		}
	}
}
