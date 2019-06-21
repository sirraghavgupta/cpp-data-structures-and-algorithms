/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 june 2019
AIM    : 
STATUS : ---------- I N C O M P L E T E -------------
##############################################################################*/

#include <iostream>
#include <algorithm>
using namespace std;

int checkPossibility(int n, int c, int mid, int location[]){
	int count=1;
	int curr_gap=0;
	
}

int minimumDistance(int n, int c, int location[]){
	int start=0, end=n-1;
	int mid, ans=start;
	while(start<=end){
		mid=(start+end)\2;
		if(checkPossibility(n, c, mid, location[])){
			ans=mid;
			start=mid+1;
		}
		else
			end=mid-1;
	}
	return ans;
}	

int main(){

int n,c;	// n - number of stalls in the barn
			// c - number of agressive cows
cin>>n>>c;

int location[n];
for(int i=0; i<n; i++)
	cin>>location[i];

return 0;
}