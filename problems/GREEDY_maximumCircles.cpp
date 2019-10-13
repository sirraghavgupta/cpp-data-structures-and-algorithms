/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : There are n circles arranged on x-y plane. All of them have their 
		 centers on x-axis. You have to remove some of them, such that no two 
		 circles are overlapping after that. Find the minimum number of circles 
		 that need to be removed.
STATUS : !!! success !!!
##############################################################################*/


#include <bits/stdc++.h>
using namespace std;

class circle{
public:
	int c;	// center
	int r;	// radius
	int s;	// start
	int e;	// end 

	void compute(){
		s = c-r;
		e = c+r;
	}
};

bool compare(circle a, circle b){
	return a.e < b.e;	// ascending order of end time 
}

int main(){

int n;
cin>>n;
circle a[n];
for(int i=0; i<n; i++){
	cin>>a[i].c;
	cin>>a[i].r;
	a[i].compute();
}

// sort the activities in increasing order of end time
sort(a, a+n, compare);

// pick the activities now such that we have more time to do other activities
// pick that which finishes early 

int count=0;	// do atleast 1 activity 
int lastend = INT_MIN;	// end time of last done activity.
for(int i=0; i<n; i++){
	// if this activity doesnt clash with the previous performed activity, pick it.
	if(a[i].s>=lastend){
		count++;   
		lastend = a[i].e;
	}
}
cout<<n-count<<endl;

return 0;
}
