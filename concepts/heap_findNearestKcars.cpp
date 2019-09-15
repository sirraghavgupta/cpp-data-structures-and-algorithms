/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : u are given n number of cars in the form of (x,y) coordinates.
		 u have to find the nearest k cars from the origin as u are
		 standing there
STATUS : !!! success !!!

NAIVE : find the distance of all cars and sort them.   - O(nlogn)
WE    : use a minHeap and custom comparator [ F U N C T O R S ]
		O(klogN) as popping out is O(logN)
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Car{
public:
	int id;
	int x;
	int y;

	Car(int id, int x, int y){
		this->id = id;
		this->x = x;
		this->y = y;
	}

	void print(){
		cout<<id<<" : ("<<x<<","<<y<<")"<<endl; 
	}

	int distance(){
		//no need to take sq. root b'coz we want to compre only 
		return x*x + y*y;
	}
};

// --- functional object = F U N C T O R  ---------------
// a functional object implementation class - MUST have atleast 1 public function which
// MUST overload the round bracket operator

class CarCompare{
public:
	bool operator()(Car a, Car b){
		return a.distance() > b.distance();
		// u can check by running whether to use > or <
		// it depends on the inner implementation of the priority Q class.
	}
	void operator()(){
		cout<<"i am a functor"<<endl;
	}
	void operator()(int a){
		cout<<"i can get parametrs also "<<a<<endl;
	}
};

// we pass parameters into the functor
// its return type can be void or bool or anyone.
/*
int main(){
	// testing of functor - what is it.

	CarCompare c;
	c();
	// so basically we have created an object of the class
	// we add () to it and it acts like a function
	// we call this a functional object.
	c(5);
}*/


int main(){

int n;	// number of cars
cin>>n;

int x[n];	// x coordinates
for(int i=0; i<n; i++)
	cin>>x[i];

int y[n];	// y coordinates 
for(int j=0; j<n; j++)
	cin>>y[j];

priority_queue<Car, vector<Car>, CarCompare> pq;

for(int i=0; i<n; i++){
	Car c(i, x[i], y[i]);
	pq.push(c);
}

int k;
cin>>k;
// get the nearest 3 cars
while(k--){
	Car c = pq.top();
	c.print();
	pq.pop();
}

return 0;
}