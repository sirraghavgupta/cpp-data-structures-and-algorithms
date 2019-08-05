#include <stdio.h>

void main(){

	int n=10;
	int f(int n);		// just prototyping
	printf("%d", f(n));
}

int f(int n){
	if(n>0)
		return(n + f(n-2));
}