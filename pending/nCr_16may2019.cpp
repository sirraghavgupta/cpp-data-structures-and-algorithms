/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 May 2019
AIM    : to find the nCr value for bigger nummbers
		 1<=n,r<=1000000
		 1<=r<=n
		 so, print nCr % 1000000007 because value cant be accomodated into variable.
STATUS :
##############################################################################*/
#include <iostream>
using namespace std;

int k=0;
int fact(int n){
    unsigned int res=1;
    const unsigned int m=1000000007;
    for(int i=2; i<=n; i++){
        res*=i;
        if(res>=1000000007){
            k++;
            res=res%m;
        }
        res=res%m;
    }
    return res;
}

/*int nCr(int n, int r){
	cout<<fact(n)<<endl;
	cout<<fact(r)<<endl;
	cout<<fact(n-r)<<endl;
	unsigned int result=(fact(n)/fact(r))/fact(n-r);
    return result;
}*/

int main() {
    int n, r;
    unsigned int numerator=1;
    cin>>n>>r;
    for(int i=n; i>n-r; i--){
    	numerator*=i;
    }
    unsigned int denominator = fact(r);
    unsigned int result = 

return 0;
}