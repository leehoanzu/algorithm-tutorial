#include <stdio.h>
#include <stdlib.h>
#include "StackManagement.h"
#include "RecursionMath.h"

int main (void) {
	int n, rlt;
	while (n != -1) {
		printf("Please input positive number you wanna calculate factorial!\n");
		scanf("%d", &n);
		if (n < 0) 
			printf("You input the negative number!\n");
		else {
			rlt = calFactorial(n);
			printf("Your result is: %d\n", rlt);
		}			
	}	
	return 0;
}
