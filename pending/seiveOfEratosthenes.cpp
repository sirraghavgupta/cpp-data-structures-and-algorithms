/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : sieve of eratosthenes --- SELF MADE
STATUS : !!! pending !!! ------ compare with actual solution of bhaiya and analyse
##############################################################################*/

#include <iostream>
using namespace std;

void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){

int n;
cin>>n;
int prime[n+1];

// initialization of array
prime[0]=0;
prime[1]=0;
for(int i=2; i<=n; i++){
	prime[i]=1;
}

// printArray(prime,n);

for(int i=3; i*i<=n; i+=2){
	if(prime[i]!=0){
		for(int j=2*i; j<=n; j=j+i){
		prime[j]=0;
	  }	
	}
} 
// printArray(prime, n);

for(int i=0; i<=n; i++){
	if(prime[i])	
		cout<<i<<" ";
}
cout<<endl;
return 0;
}