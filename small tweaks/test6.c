/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : program to show octal number interpretation 
STATUS : !!! success !!!
##############################################################################*/

#include <stdio.h> 
  
int main() 
{ 
    int x = 012; 		// will be treated as octal now
    printf("%d\n", x); 	// prints the integer version of octal 12 --- 10


/*
In C octal escape sequence is represented by \ followed by three octal digits. 
Note that one or two octal digits are also allowed. An octal sequence ends either 
ends after three octal digits following \ or when a digit after \ is not an octal digit.
*/
    char s1[] = "31\01267"; 
    printf("%s\n", s1); 

/*
If we look at the output then after 31 a newline character is printed and then 67 is 
printed. This is because \012 is interpreted as \n or new line character.Actually, \012 
represents octal escape sequence for \n or newline. Octal value of 12 in decimal is 10 
and in ASCII it represents newline.
*/

    char s2[] = "31\12367"; 
    printf("%s", s2); 
    printf("\n"); 

/*
In str \123 is interpreted as octal escape sequence and value of octal 123 is 83 and 
character corresponding to it in my machine is ‘S’ as my machine uses ASCII. It can be 
different if character set used is not ASCII.
In str2 \77 is interpreted as an octal escape sequence and not \779. So, the value of 77 
is 63 in decimal and in ASCII it is '?'
*/

    char s3[] = "11\77967"; 
    printf("%s\n", s3); 
    return 0; 
} 


