/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : calculate the total number of ways to fill a 4Xn grid with tiles of 
		 size 1X4 and 4X1 only. use recursion.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int tilingWays(int n){
	if(n<0)
		return 0;
	if(n<4)
		return 1;
	return tilingWays(n-1) + tilingWays(n-4);
}

int main(){

int n;
cin>>n;
cout<<tilingWays(n)<<endl;

return 0;
}