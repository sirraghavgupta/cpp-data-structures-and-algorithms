/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print a middle downward pyramid
				*
			   * *
			  * * *
			 * * * *
			* * * * *
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

for(int i=0; i<n; i++){
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