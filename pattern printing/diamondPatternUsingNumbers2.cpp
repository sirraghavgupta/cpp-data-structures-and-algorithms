/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print diamond pattern using numbers.
			1
		   2 2
		  3 3 3 
		 4 4 4 4
		  3 3 3
		   2 2
		    1
		    
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

// upward pyramid
for(int i=0; i<n; i++){
	//print spaces
	for(int j=0; j<n-i-1; j++){
		cout<<" ";
	}

	// print *s
	for(int j=0; j<=i; j++){
		cout<<i+1<<" ";
	}
	cout<<endl;
}

// downward pyramid
for(int i=n-2; i>=0; i--){
	//print spaces
	for(int j=0; j<n-i-1; j++){
		cout<<" ";
	}

	// print *s
	for(int j=0; j<=i; j++){
		cout<<i+1<<" ";
	}
	cout<<endl;
}
return 0;
}