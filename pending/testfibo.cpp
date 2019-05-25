/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 May 2019
AIM    : 
STATUS :
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

int t;	// number of test cases
cin>>t;

int testCase[t+1];
for(int i=1; i<=t; i++){
	cin>>testCase[i];
}

sort(testCase+1, testCase+t+1);

for(int i=1; i<=t; i++){
	cout<<testCase[i]<<endl;
}

return 0;

while(t>0){ 	// process for all test cases
	int n;
	cin>>n; 	// number of term for current case

	int a1=1, a2=1;
	for(int i=3; i<=n; i++){
		int temp;
		temp=(a1+a2)%1000000007;
		a1=a2;
		a2=temp;
	}	
	cout<<a2<<endl;

t--;	// for next test case
}

return 0;
}