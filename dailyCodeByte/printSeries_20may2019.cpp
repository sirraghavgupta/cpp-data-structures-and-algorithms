/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 May 2019
AIM    : to find first n1 terms of a series (3n+2) which are not divisible by n2.
	     take n1 and n2 as input.
	     0<n1,n2<100
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int n1, n2;
cin>>n1>>n2;

int count=1; 					// number of terms printed 
for(int i=1; count<=n1; i++){ 	// run untill n1 terms are printed 
	int term=3*i+2;
	// cout<<"evaluated term is: "<<term<<endl;
	if(term%n2!=0){ 			// check validity of ter
		cout<<term<<endl;
		count++; 				// increment the number of terms printed
	}
}

return 0;
}