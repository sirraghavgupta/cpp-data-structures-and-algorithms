/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 october 2019
AIM    : see the screen shots
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

int t;
cin>>t;

int l;		// length of kingdom
int b;		// breadth of kingdom
int n;		// number of towers 

while(t--){		
	cin>>l>>b>>n;	
	
	vector<int> x, y;	// x and y coordinates 
	int val;

	for(int i=0; i<n; i++){	// get coords of towers 
		cin>>val;
		x.push_back(val);
		cin>>val;
		y.push_back(val);
	}

	sort(x.begin(), x.end());		//increasing order
	sort(y.begin(), y.end());

	x.push_back(l+1);
	y.push_back(b+1);

	long long int mX = x[0]-1, mY=y[0]-1;	// for leftmost coordinate 

	// calculate the maximum value of dX and dY.
	for(int i=1; i<x.size(); i++){

		int diffX = x[i]-x[i-1]-1;
		if(diffX>mX)
			mX = diffX;

		int diffY = y[i]-y[i-1]-1;
		if(diffY>mY)
			mY = diffY;

	}	
	
	int answer = mY*mX;
	cout<<mY*mX<<endl;

}

return 0;
}