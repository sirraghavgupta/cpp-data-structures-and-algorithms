/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : check the cyclicity of char data type
STATUS : !!!  cyclicity of char data type is not possible
##############################################################################*/

#include <stdio.h>

void main(){

char c = 'x'+ 256;	// gives error
printf("c", c);
}