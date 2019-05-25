/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 May 2019
AIM    : 
STATUS :
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[410];

int fibo(int a1, int a2, int n){
	if(n%500==1)	return a1;
	else if(n==2)	return a2;
	else{
		for(int i=3; i<=n; i++){
		int temp;
		temp=(a1+a2)%1000000007;
		a1=a2;
		a2=temp;
		}	
  	}
}

int main(){

int t;	// number of test cases
cin>>t;


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