/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : how negative numbers are stored
STATUS : !! important	
##############################################################################*/


/*
	integer variable is of 32 bits
	so 1 is stored as 		00000000 00000000 00000000 00000001
	for -1 take 2's complement
	so -1 is stored as 		11111111 11111111 11111111 11111111

	-1<<4 ---- 				11111111 11111111 11111111 11110000
	in hexadecimal its 		f   f    f   f    f   f    f   0
							fffffff0

							!!!  BEAUTIFUL  !!!
*/

#include <stdio.h>

void main(){
	printf("%x", -1<<4);
}