/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print a hollow pyramid or a upward triangle
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

for(int i=1; i<=n; i++){
	// print spaces
	for(int j=0; j<n-i; j++){
		cout<<" ";
	}

	// print stars
	int k=0;
	while(k!=(2*i-1)){
		if(k==0 || k==(2*i-2))
			cout<<"*";

		else
			cout<<" ";
		k++;
	}
	cout<<endl;
}

// print last row
	for(int l=0; l<2*n-1; l++)
		cout<<"*";
	cout<<endl;

return 0;
}