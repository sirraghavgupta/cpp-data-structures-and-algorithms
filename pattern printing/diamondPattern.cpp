/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print diamond pattern using stars
				*
			   * *
			  * * *
			 * * * *
			* * * * *
			 * * * * 
			  * * *
			   * *
			    *
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

// print the upward pyramid
for(int i=0; i<n; i++){
	//print spaces
	for(int j=0; j<n-i-1; j++){
		cout<<" ";
	}

	// print *
	for(int j=0; j<=i; j++){
		cout<<"* ";
	}
	cout<<endl;
}

// print inverted pyramid
for(int i=n-2; i>=0; i--){
	//print spaces
	for(int j=0; j<n-i-1; j++){
		cout<<" ";
	}

	// print *s
	for(int j=0; j<=i; j++){
		cout<<"* ";
	}
	cout<<endl;
}
return 0;
}