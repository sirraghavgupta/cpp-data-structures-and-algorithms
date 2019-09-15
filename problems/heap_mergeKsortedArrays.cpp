/*##############################################################################
AUTHOR : RAGHAV GUPairTA
DATE   : 15 september 2019
AIM    : to merge 'k' sorted arrays together into one

NAIVE  : concatenate the 3 arrays and apply sorting - O(knLog(kn))
EFFICIENT : using heaps
TIME   : 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

// class for keeping object in heap
class Pair{
public:
	int val;
	int index;

	Pair(){

	}

	Pair(int val, int index){
		this->val = val;
		this->index = index;
	}
};

// functor for minHeap 
class CarCompare{
public:
	bool operator()(Pair a, Pair b){
		return a.val > b.val;
	}
};

// to print the heap 
void printHeap(priority_queue<Pair, vector<Pair>, CarCompare> pq){

	while(!pq.empty()){
		cout<<pq.top().val<<", ";
		pq.pop();
	}
	cout<<endl;
}





int main(){

int k;	// k = number of arrays
cin>>k;

vector<int> input[k];	// vector array

// input the arrays from user
int val;  
for(int i=0; i<k; i++){
	// cout<<"reading "<<i<<" vector"<<endl;

	int n;	//number of elemnets in this particular vector
	cin>>n;
	while(n--){	// get n elements 
		cin>>val;
		input[i].push_back(val);
	}
	input[i].shrink_to_fit();	// remove redundant space from vector
}

// check input by printing 
cout<<endl<<"ur input is: "<<endl;
for(int i=0; i<k; i++){
	int n = input[i].size();
	int j=0;
	while(j<n){
		cout<<input[i][j]<<" ";
		j++;
	}
	cout<<endl;
}

vector<int> output;		//output vector

priority_queue<Pair, vector<Pair>, CarCompare> pq;	// minHeap
	
int pointers[k]={0};	// pointers of current location in all arrays
for(int i=0; i<k; i++){
	// insert first element of all vectors into heap 
	Pair p(input[i].at(pointers[i]), i);
	pq.push(p);
}

// check initially built heap
printHeap(pq);

// processing 
while(1){
	Pair p = pq.top();
	pq.pop();

// if INT_MAX is the min value, it means we are done as all values in heap must be INT_MAX 
	if(p.val==INT_MAX)
		break;

	output.push_back(p.val);
	int index = p.index;
	pointers[index]++;	// increment the corr. pointer
	if(pointers[index]>input[index].size()-1){
		p.val = INT_MAX;	// if vector got finished 
	}
	else
		p.val = input[index].at(pointers[index]);
	pq.push(p);
}
output.shrink_to_fit();
for(int i=0; i<output.size(); i++){
	cout<<output[i]<<" ";
}
cout<<endl;

return 0;
}