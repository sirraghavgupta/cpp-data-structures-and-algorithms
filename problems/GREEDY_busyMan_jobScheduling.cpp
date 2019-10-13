/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : there is a man who have alot of activities to do.
		 each actvity has a start and end time
		 the actvities may be overlapping
		 we need to find the maximum number of non-overlapping activities he can do
		 SPOJ - BUSYMAN
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class activity{
public:
	int s;	// start
	int e;	// end 
};

bool compare(activity a, activity b){
	return a.e < b.e;	// ascending order of end time 
}

int main(){

int n;
cin>>n;
activity a[n];
for(int i=0; i<n; i++){
	cin>>a[i].s;
	cin>>a[i].e;
}

// sort the activities in increasing order of end time
sort(a, a+n, compare);

// pick the activities now such that we have more time to do other activities
// pick that which finishes early 

int count=0;	// do atleast 1 activity 
int lastend = 0;	// end time of last done activity.
for(int i=0; i<n; i++){
	// if this activity doesnt clash with the previous performed activity, pick it.
	if(a[i].s>=lastend){
		count++;   
		lastend = a[i].e;
	}
}
cout<<count<<endl;

return 0;
}
