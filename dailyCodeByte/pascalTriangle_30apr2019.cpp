/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 april 2019
AIM    : to print pascal triangle
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int fact(int n){                // to evaluate factorial
    if(n==0)    return 1;
    return n*fact(n-1);
}

int nCr(int n, int r){          // to evaluate binomial coefficient
    return fact(n)/(fact(r)*fact(n-r));
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        // for blank spaces
        for(int j=n-1-i; j>0; j--)
            cout<<"\t";
        
        // for printing values
        for(int j=0; j<=i; j++)
            cout<<nCr(i,j)<<"\t";
        cout<<endl;
    }

return 0;
}
