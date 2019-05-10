/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 May 2019
AIM    : to calculae the total number of squares in an n*n grid
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){


int n;
cin>>n;
while(n!=0){
	int result = n*(n+1)*(2*n+1)/6;
	cout<<result<<endl;
	cin>>n;
}

return 0;
}