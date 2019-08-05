#include <stdio.h>

void main(){

	int a[] = {124, 771, 313, 154, 313, 137, 124, 771, 154};
	int temp =0, i=0;
	for(i=0; i<9; i++){
		temp^=a[i];
	}
	printf("%d", temp);

	// awesome - its the tecnique to find unique number
	// xor of 2 numbers becomes 0
} 