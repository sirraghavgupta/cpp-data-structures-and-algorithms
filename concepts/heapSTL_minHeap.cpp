/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 september 2019
AIM    : implement min heap - priority queue using STL
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
#include <vector>
// always use bits/stdc++ if u have multiple headers - it helps in online rounds.
using namespace std;

int main(){

priority_queue<int, vector<int>, greater<int>> pq_min;

int val;
cin>>val;
while(val!=-1){
	pq_min.push(val);
	cin>>val;
}

/* 
	by default it implements the maxheap. 
	to implement a min heap, we need to pass extra parameters
	0. template parameter is compulsory 
	1. vector of integers always
	2. a comparator function - comparators can be default or custom made
	   for min heap, we have a greater<int> comparator which allows the greater 
	   elements to go down.
*/
while(!pq_min.empty()){
	cout<<pq_min.top()<<", ";
	pq_min.pop();
}	
cout<<endl;

return 0;
}