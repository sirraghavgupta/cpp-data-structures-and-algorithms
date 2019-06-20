/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 june 2019
AIM    : to give the index of the lucky number in the lucky number series
		 a lucky number is the one which is made up of only 4 and 7s.
		 ex - 4, 7, 44, 47, 74, 77 .................. 
STATUS : !!! success !!!
NOTE   : this approach is exactly same with mine in coding but lil different 
 	 	 to understand on paper.
 	 	 but, in coding also, he is using a char array approach to make it 
 	 	 easy to get the length and digits of the number.
##############################################################################*/
#include <iostream>
#include <string.h>
#define ll long long int
using namespace std;

int main(){

char num[20];	// to store the lucky number
cin>>num;

int len = strlen(num);		// get length of number
ll ans = 0;		// lucky number is very large, so index can also be large 

ans = (1<<len) - 2;	// count the numbers having lesser digits than current number

// iterate over all the digits, and assign corresponding weight where digit is 7
for(int i=len-1,pos=0; i>=0; i--,pos++){
	if(num[i]=='7')
		ans += (1<<pos);
}
ans+=1;		// index adjustment 
cout<<ans<<endl;	

return 0;
}