/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 May 2019
AIM    : 
STATUS :
##############################################################################*/
#include <iostream>
using namespace std;

int arr[1000000000];
int main(){

int t;	// number of test cases
cin>>t;

while(t>0){ 	// process for all test cases
	int n;
	cin>>n; 	// number of term for current case
	
	arr[1]=1;	// initialise the first term
	arr[2]=1;	// initialise the second term

	for(int i=3; i<=n; i++){	// prepare the fibonacci series upto n terms
		arr[i]=(arr[i-1]+arr[i-2]);	
		arr[i] = (arr[i]>=1000000007)?arr[i]%1000000007:arr[i]; 	// modulo operation
	}
	cout<<arr[n]<<endl;

	t--;	// for next test case
}
/*for(int i=1; i<=n; i++){
	cout<<arr[i]<<endl;
}*/

return 0;
}