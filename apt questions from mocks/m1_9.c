#include <stdio.h>
void main(){


int m = 1000, *n, **o, ***p;
n = &m;
o = &n;
p = &o;
printf("%d %d %d %d \n", m, *n, **o, ***p);

}