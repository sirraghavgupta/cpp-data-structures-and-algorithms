/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 october 2019
AIM    : We are given two coins of value x and y. We have to find the maximum 
		 of value of a XOR b where x <= a <= b <= y.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

int a,b;
cin>>a>>b;

int max = a^b;
int curr;
for(int i=a; i<=b;i++){
	for(int j=a+1; j<b; j++){
		curr = i^j;
		max = (curr>max)?curr:max;
	}
}
cout<<max<<endl;

return 0;
}