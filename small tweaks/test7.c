/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : size of pointer variable
STATUS : !! pointer variable takes the size of 8bytes - like long long int	
##############################################################################*/

#include <stdio.h>

void main(){

char *c;
char h = 'x';
c = &h;

int *p;
int b = 5;
p = &b;

printf("%d, %d, %d\n", sizeof(c), sizeof(*c), sizeof(h));
printf("%d, %d, %d\n", sizeof(p), sizeof(*p), sizeof(b));

}