/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : to find out the k largest elements in a running stream of numbers.
	     u can't store all the numbers because the count may be indefinite
	     at everytime, u have to tell the k largest nunmbers 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int>> pq){
	// we used pass by value - so actual heap will not be altered
	// good idea to print
	while(!pq.empty()){
		cout<<pq.top()<<", ";
		pq.pop();
	}
	cout<<endl;
}

int main(){

priority_queue<int, vector<int>, greater<int>> store;	//min heap

int k;	// number of greatest elements u want everytime
cin>>k;	// or max size of heap

int size = 0; // size of heap

int data;
cin>>data;
while(data!=-1){
	
	if(data == -2 )
		printHeap(store);

	if(size>=k){
		if(data>store.top()){
			store.pop();
			store.push(data);
		}
	}
	else{
		store.push(data);
		size++;
	}

	cin>>data;
}

/*	// another way to process runnig stream on online compilers bcoz they take input 
	// from file
while(scanf("%d", &data)!=EOF){
	// another approach ---------------------------------- BETTER
	// use CSTDIO
}*/

return 0;
}