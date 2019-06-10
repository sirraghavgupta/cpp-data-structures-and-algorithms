/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 june 2019
AIM    : to find out the square root of a number by binary search 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

float squareRoot(int n, int p){	// similar to binary search

	int start=0, end=n;	
	int mid;
	float ans=-1;

	while(start<=end){

		mid = (start+end)/2;

		if(mid*mid==n){	 // perfect square root found, then return it
			ans = mid;
			break;
		}

		else if(mid*mid<n){	// look for a better integral part if exists
			start = mid+1;
			ans = mid;
		}
		else
			end = mid-1;
	}

	// evaluate fractional part if not perfect square
	if(ans*ans<n){
		float increment=0.1;
		
		while(p>0){			// run for all decimal places required 
			while(ans*ans<n){
			ans+=increment;
			}	
			ans-=increment;
		increment/=10;
		p--;	
		}
	}

	return ans;
}
// -------------------------------------------------


int main(){

int n;		// number 
cin>>n;

int p;		// precision - number of decimal places 
cin>>p;

cout<<squareRoot(n, p)<<endl;

return 0;
}