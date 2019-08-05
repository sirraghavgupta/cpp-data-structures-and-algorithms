#include <stdio.h>
void main(){


	int num;
	printf("enter a number\n");
	scanf("%d", &num);
	if(num%2 == 0)
		goto even;
	else
		printf("the number is odd\n");
	even:
	printf("the number is even\n");
}