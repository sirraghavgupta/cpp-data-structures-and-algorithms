/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 4 july 2019
AIM    : calculate the total number of ways to fill a nXm grid with tiles of 
		 size 1Xm and mX1 only. use recursion.
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

unsigned const int M=1000000007;
long long int tilingWays(int n, int m){
	
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	if(n<m)
		return 1;
	if(n==m)
		return 2;
	return tilingWays(n-1, m)%M + tilingWays(n-m, m)%M;
}

int main(){

int t;
cin>>t;

while(t>0){
	int n, m;
	cin>>n>>m;
	cout<<tilingWays(n, m)<<endl;
  t--;
}

return 0;
}