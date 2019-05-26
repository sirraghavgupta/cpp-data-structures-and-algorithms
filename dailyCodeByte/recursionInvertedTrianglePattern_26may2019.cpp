/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 May 2019
AIM    : to print inverted triangle pattern by recursion
		for n=5
		*	*	*	*	*
		*	*	*	*
		*	*	*
		*	*
		*
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

void printInvertedTriangle(int n){
	if(n>=1){
		for(int i=0; i<n; i++) 	// print the top row of the triangle
			cout<<"*\t";
		cout<<endl;
		return printInvertedTriangle(n-1); 	// and then call for smaller triangle
	}
	else return;
}

int main(){

int n;
cin>>n;

printInvertedTriangle(n);

return 0;
}