/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : same as the maximumElementInWindowOfSize_K_SlidingWindow
		 There is a group of MMA fighters standing together in a line. Given the 
		 value of their strengths, find the strength of the strongest fighter in 
		 continuous sub-groups of size k.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <deque>

using namespace std;

int main(){

int n,k;
cin>>n;
int arr[n];
for(int i=0; i<n; i++){
	cin>>arr[i];
}
cin>>k;

deque<int> q(k);

// process first k elements separately
int i;
for(i=0; i<k; i++){
	while(!q.empty() && arr[q.back()]<=arr[i]){
		q.pop_back();
	}
	q.push_back(i);
}

// process remaining elements
for(; i<n; i++){
	// print the answer of previous window
	cout<<arr[q.front()]<<" ";

	// 1. remove the elements which are in the deck but doesnt belong to the curr window
	while(!q.empty() && (q.front()<=i-k)){
		q.pop_front();
	}
	// 2. remove the elements fron the deck which cant be the answer
	while(!q.empty() && (arr[q.back()]<=arr[i])){
		q.pop_back();
	}

	// 3. push the current element
	q.push_back(i);
}
cout<<arr[q.front()]<<endl;
return 0;
}