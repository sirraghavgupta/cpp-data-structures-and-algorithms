/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 august 2019
AIM    : to find the maximum elemnent in all subarrays of size k
STATUS : !!! success  !!! --- very difficult
TIME   : O(n+k)  -- best and very efficient
##############################################################################*/

#include <iostream>
#include <deque>
using namespace std;

int main(){

int n;
int a[100000];
int k;

// input array first 
cin>>n;
for(int i=0; i<n; i++)
	cin>>a[i];
cin>>k;					// size of window

deque<int> Q(k);


// we have to process first k elements separately
int i;
for(i=0; i<k; i++){
	while(!Q.empty() && a[i]>a[Q.back()]){
		Q.pop_back();
	}
	Q.push_back(i);
}
// now the biggest of the first window is in the front of deck




// process remaining elements
for(; i<n; i++){
	cout<<a[Q.front()]<<" ";	// print the biggest of the precious window

	// 1. remove the elements which are not the part of the window (contraction)
	while(!Q.empty() && (Q.front()<=i-k)){
		Q.pop_front();
	}
	// 2. remove the elements which are not useful and are in window
	while(!Q.empty() && (a[i]>=a[Q.back()])){
		Q.pop_back();
	}
	// 3. add the new elements(Expansion)
	Q.push_back(i);
}
// for the last window
cout<<a[Q.front()]<<endl;



/*
note:
1. everytime the deck will contain some indices from the current window [only from the current]
2. everytime the biggest element index will be at the front of the deck
*/

return 0;
}