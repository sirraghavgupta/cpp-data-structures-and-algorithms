/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : return value of assignent statement
STATUS : !!! assignment operator returns the value assigned
##############################################################################*/

#include <stdio.h>

void main(){

int b;
int a = 2 + (b=5);		// leads to a=7
printf("%d\n", a=10); 	// prints 10 because a=10 returns 10

if(b=100)
	printf("observation pending\n");
if(a=0)
	printf("observation true\n");


}