/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 july 2019
AIM    : to implement the stack data structure using array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

class stack{
private:
	int arr[100];
	int size;		// max size of the stack
	int top;		// pointer to the top of stack

public: 
	stack(int n){	// choose the size of stack while creating object
		size = n;
		top=-1;		// stack empty initially
	}

	bool isEmpty(){
		return top<0;
	}

	int getTop(){
		if(!isEmpty())
			return arr[top];
		else
			cout<<"stack empty"<<endl;
		return -99999999;
	}

	void pop(){
		if(!isEmpty())
			top--;
		else
			cout<<"stack empty"<<endl;
	}

	bool isFull(){
		return top>size-1;
	}

	void push(int n){
		if(!isFull()){
			top++;
			arr[top] = n;
		}
		else{
			cout<<"stack already full"<<endl;
		}
	}

	void print(){
		for(int i=top; i>=0; i--){
			cout<<arr[i]<<endl;
		}
	}
};

int main(){

stack stk(10);

int choice;
do{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. push"<<endl;
	cout<<"2. pop"<<endl;
	cout<<"3. get top"<<endl;
	cout<<"4. print"<<endl;
	cout<<"5. exit"<<endl;

	cin>>choice;
	switch (choice){
		case 1: int data;
				cin>>data;
				stk.push(data);
				break;
		case 2: stk.pop();
				break;
		case 3:	cout<<stk.getTop()<<endl;
				break;
		case 4: stk.print();
				break;
		case 5: exit(0);
		default: cout<<"invalid input"<<endl;
				break;
	}

}while(choice!=0);

return 0;
}