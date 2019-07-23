/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement the stack data structure using vector.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <vector>
using namespace std;

class stack{
private:
	// by using vector,we dont need a pointer to top of stack becse of inbuilt functions
	vector<int> a;	

public: 
	void push(int data){
		a.push_back(data);
	}

	void pop(){
		if(!isEmpty())
			a.pop_back();
	}

	int top(){
		if(!isEmpty())
			return a[a.size()-1];
		else 
			return -99999999;
	}

	bool isEmpty(){
		return a.size()==0;
	}

	void print(){
		for(int i=a.size()-1; i>=0; i--){
			cout<<a[i]<<endl;
		}
	}
	
};

int main(){

stack stk;

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
		case 3:	cout<<stk.top()<<endl;
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