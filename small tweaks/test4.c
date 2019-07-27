/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : back slash characters in c
STATUS : !!! success !!!
NOte   : refer to the C aptitude shots for this explanation
##############################################################################*/

#include <stdio.h>

void main(){

printf("\npq");
printf("\brs");
printf("\rtq");
printf("\n");

printf("Hello Geeks\b\b\b\bF\n"); 

printf("Hello friends"); 
printf("\v Welcome to GFG");
printf("\n");

printf("Hello fri\rends\n");

char* s = "A\0725"; 	// octal escape sequence
printf("%s\n", s); 

char* s1 = "B\x4a"; 	// hexadecimal 
printf("%s\n", s1);

}