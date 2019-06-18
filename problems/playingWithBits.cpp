/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to count the number of set bits in a given range
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int q;
cin>>q;	
int ans;

while(q>0){

	ans=0;
	int s,e;
	cin>>s>>e;
	
	for(int i=s; i<=e; i++){
		int n=i;
		for( ;n>0; n=n>>1)		
			ans = ans + (n&1);
	}
	cout<<ans<<endl;

q--;
}

return 0;
}