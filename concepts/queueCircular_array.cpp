	/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement a circular queue using fixed size arrays.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

template<typename T>	// generic class
class queue{
private:
	int f;	// front
	int r;	// rear
	int ms;	// maximum size
	int cs;	// current size
	T *a;	// generic array

public:
	// ctor
	queue(int size=5){	// default argument
		ms = size;
		cs = 0;
		f = 0;		// front
		r = ms-1;	// rear
		a = new T[ms];
	}
	bool full(){
		return cs==ms;
	}
	bool empty(){
		return cs==0;
	}
	void push(T d){
		if(!full()){
			r = (r+1)%ms;
			a[r] = d;
			cs++;
		}
		else{
			cout<<"queue full"<<endl;
		}
	}
	void pop(){
		if(!empty()){
			f = (f+1)%ms;
			cs--;
		}
	}
	void print(){
		for(int i=0; i<cs; i++){
			int index = (f+i)%ms;
			cout<<a[index	]<<" ";
		}
		cout<<"end"<<endl;
	}	
	T front(){
		if(empty())
			cout<<"queue empty"<<endl;
		return a[f];
	}
	/*
	// just for learning purpose
	void checkArray(){
		for(int i=0; i<ms; i++){
			cout<<a[i]<<" ";
		}
		cout<<"end"<<endl;
	}*/
};

int main(){

queue<int> q;

int choice;
do{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. enqueue"<<endl;
	cout<<"2. dequeue"<<endl;
	cout<<"3. get front"<<endl;
	cout<<"4. print"<<endl;
	cout<<"5. exit"<<endl;

	cin>>choice;
	switch (choice){
		case 1: int data;
				cin>>data;
				q.push(data);
				break;
		case 2: q.pop();
				break;
		case 3:	cout<<q.front()<<endl;
				break;
		case 4: q.print();
				break;
		case 5: exit(0);

		// case 6: q.checkArray();
		// 		break;

		default: cout<<"invalid input"<<endl;
				 break;
	}

}while(choice!=0);

return 0;
}