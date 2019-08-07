/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 august 2019
AIM    : We are given a circular array, print the next greater number for every 
		 element. If it is not found print -1 for that number. To find the next 
		 greater number for element Ai , start from index i + i and go uptil the 
		 last index after which we start looking for the greater number from the 
		 starting index of the array since array is circular.
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

void nextGreater(queue<int> *q){
	// find the answer
	queue<int> *temp;
	temp = new queue<int>();
	// q = &que;
	int n = q->size();
	for(int i=0; i<n; i++){
		int ans;
		// get and remove the current candidate 
		int curr = q->front();
		q->pop();

		// keep popping untill u get a bigger element
		while(!q->empty() && q->front()<=curr){
			temp->push(q->front());
			q->pop();
		}
		// if greater element not found or its the last element
		if(q->empty()){
			ans=-1;	
		}
		else{
			ans = q->front();
			// transfer the elements
			while(!q->empty()){
				temp->push(q->front());
				q->pop();
			}
		}
		swap(temp, q);
		cout<<ans<<" ";
	}
	cout<<endl;
}

int main(){

queue<int> q;

// build the queue
int n;
cin>>n;
int data;
for(int i=0; i<n; i++){
	cin>>data;
	q.push(data);
}

nextGreater(&q);

return 0;
}