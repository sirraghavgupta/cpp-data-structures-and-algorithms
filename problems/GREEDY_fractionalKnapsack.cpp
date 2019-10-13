/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : implement the fractional knapsack problem
STATUS : !!! complete - NOT EVALUATED  !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class item{	
public:
	int weight;
	int cost;
	float ratio;

	void calculate(){
		ratio = (float)cost/weight;
	}
};

bool compare(item a, item b){
	return a.ratio > b.ratio;
}

int main(){

int n;	// number of items in the shop
cin>>n;

// get the items 
item items[n];
for(int i=0; i<n; i++){
	cin>>items[i].weight;
	cin>>items[i].cost;
	items[i].calculate();
}

// sort in decreasing order of ratios 
sort(items, items+n, compare);

int capacity;
cin>>capacity;

int i=0;
float profit = 0;		

while(capacity>0 && i<n){	// unless the bag gets filled to max
	if(items[i].weight<capacity){
		// he can pick the complate item 
		capacity -= items[i].weight;
		profit += items[i].cost;
	}
	else{
		// he needs to pick partial amount
		profit += capacity*items[i].ratio;
		capacity = 0;
	}

	i++;
}

cout<<profit<<endl;

return 0;
}