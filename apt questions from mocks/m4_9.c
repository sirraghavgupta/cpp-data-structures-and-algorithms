#include <stdio.h>

int f(int n){
	if(n<=1)
		return n;
	else
		return 2*f(n/2)+n%2;
}

void main(){

	printf("%d\n", f(1471));
} 