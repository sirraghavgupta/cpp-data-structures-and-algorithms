/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to check the associativity of function calls.
STATUS : !!!  !!!
##############################################################################*/


// Associativity is not used in the below program. Output 
// is compiler dependent. 
#include<stdio.h> 
int x = 0; 
int f1() 
{ 
	x = 15; 
	return x; 
} 
int f2() 
{ 
	x = 25; 
	return x; 
} 
int main() 
{ 
	int p = f2() + f1(); 
	printf("%d ", x); 
	printf("%d ", p);
	return 0; 
}
