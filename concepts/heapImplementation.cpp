/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to implement heap using vectors
STATUS : !!! success !!!
TIME   :
building the tree = O(n)		-- special logic, google
insetion          = O(logN)
deletion          = O(logN)
reheapify 		  = O(logN)
get min/max 	  = O(1)
##############################################################################*/

#include <iostream>
#include <vector>
using namespace std;

class heap{
private:
	vector<int> v;
	bool minHeap;	// denotes type of heap 

	bool compare(int i, int p){
		// gives ideal comparison for the type of heap.
		if(minHeap)
			return i<p;
		else
			return i>p;
	}

	void heapify(int p){	//RECURSIVE 
			// get the children 
			int left = 2*p;
			int right = 2*p +1;

			// assume current is min.
			int min = p; 
			if(left<v.size() && compare(v[left], v[p]))
				min = left;
		
			if(right<v.size() && compare(v[right], v[min]))
				min = right;
			
			if(min!=p){
				swap(v[min], v[p]);
				heapify(min);
			}
		}

public:
	heap(bool type = true){
		minHeap = type;		// by defualt it'ld be a minHeap 
		v.push_back(-1);	// block the 0th index 
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;
	}

	void push(int n){
		// insert data at last
		v.push_back(n);
		//bring that to appropriate location 
		int i = v.size()-1;
		int parent = i/2;

		while(parent>=1 && compare(v[i], v[parent])){
			swap(v[i], v[parent]);
			i=parent;
			parent = parent/2;
		}
	}

	void pop(){
		if(empty())
			return;
		int last = v.size() - 1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}
};

int main(){

heap h(true);
int val;
cin>>val;

while(val!=-1){
	h.push(val);
	cin>>val;
}

while(!h.empty()){
	cout<<h.top()<<endl;
	h.pop();
}

return 0;
}