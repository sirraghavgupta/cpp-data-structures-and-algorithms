/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to find the median at any point in a running stream
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int>> pq){

	while(!pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
}
void printHeap(priority_queue<int> pq){

	while(!pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
}

int main(){

priority_queue<int> leftQ;									// max heap
priority_queue<int, vector<int>, greater<int>> rightQ;		// min heap 
int leftSize = 0, rightSize = 0;

// initial start by one elenment 
int val;
cin>>val;
leftQ.push(val);
leftSize++;
float median = val;

// iterate now 
cin>>val;
while(val!=-1){
	if(val==-3){
		printHeap(leftQ);
		printHeap(rightQ);
	}

	else if(val==-2){
		// user queries to print median 
		cout<<median<<endl;
	}

	else{
		// insert a new element. 
		if(val>=median){
			// cout<<"inserting in right"<<endl;
			rightQ.push(val);
			rightSize++;
		}
		else{
			// cout<<"inserting in left"<<endl;
			leftQ.push(val);
			leftSize++;
		}
	}

	{	// balancing of heaps 
		if(leftSize - rightSize >1){
			rightQ.push(leftQ.top());
			leftQ.pop();
			leftSize--;
			rightSize++;
		}
		else if(rightSize - leftSize>1){
			leftQ.push(rightQ.top());
			rightQ.pop();
			rightSize--;
			leftSize++;
		}	
	}
	
	{
		// update the median
		if(leftSize==rightSize)
			median = (float)(leftQ.top()+rightQ.top())/2;
	
		else if(leftSize == rightSize+1)
			median = leftQ.top();
		
		else
			median = rightQ.top();
	}

cin>>val;
}

return 0;
}