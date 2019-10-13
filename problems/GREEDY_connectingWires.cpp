/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : there are n number of balls of 2 colors placed linearly at a distance of 
		 1 - 1 from each other
		 find the minimum length of wire required to connect every blue ball to
		 exactly 1 ball of green color. 
STATUS : !!! completed - not evaluated  !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

int n;	// number of dots 
cin>>n;

int x[n];	// blue or color 1
int y[n];	// green or color 2
for(int i=0; i<n; i++)
	cin>>x[i];

for(int i=0; i<n; i++)
	cin>>y[i];

sort(x, x+n);
sort(y, y+n);

int length=0;
for(int i=0; i<n; i++){
	length += abs(x[i]-y[i]);
}

cout<<length<<endl;

return 0;
}