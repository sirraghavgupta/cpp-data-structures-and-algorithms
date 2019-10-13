/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 october 2019
AIM    : A religious king wants to build the largest temple in his kingdom . 
		 To build the largest temple he needs to find the area of the largest 
		 suitable land . Given co-ordinates which denotes rivers flowing through 
		 the point horizontally as well as vertically , find the largest area 
		 possible to make the grand temple.
		 -- same the defence of kingdom problem. 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){


int n;		// number of towers 

cin>>n;	

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

// x.push_back(l+1);
// y.push_back(b+1);

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

return 0;
}