/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 November 2019 
AIM    : implement fibonacci series by using DP to understand the concept of DP
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int ans[1000];
// this is our memopad. we are writing out outputs here. 

int fibo(int k){
	if(ans[k]==-1){
		if(k==0)
			ans[k] = 0;
		else if(k==1)
			ans[k] = 1;
		else{
			ans[k] = fibo(k-1) + fibo(k-2);
		}
	}

	return ans[k];
}

int main(){

int k;
cin>>k;

for(int i=0; i<=k; i++){
	ans[i] = -1;
}

cout<<fibo(k)<<endl;

return 0;
}

