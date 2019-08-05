/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print hollow inverted pyramid or inverted triangle
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

// print first row
for(int i=0; i<2*n+1; i++)
	cout<<"*";
cout<<endl;


for(int i=n; i>=1; i--){
	// print spaces
	for(int j=0; j<n-i+1; j++){
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

return 0;
}