/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 september 2019
AIM    : implement min heap - priority queue using STL
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

int main(){

priority_queue<int> pq_max;

int val;
cin>>val;
while(val!=-1){
	pq_max.push(val);
	cin>>val;
}

// by default it implements the maxheap. and again its a templeate.

/*
	basic functions are 
	1. push()
	2. pop()
	3. top()
	4. empty()
*/
while(!pq_max.empty()){
	cout<<pq_max.top()<<", ";
	pq_max.pop();
}	
cout<<endl;

return 0;
}