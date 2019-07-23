/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement the TEMPLATED stack data structure using vector.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <vector>
// #include <cstring>
using namespace std;

template<typename T>
class stack{
private:
	// by using vector,we dont need a pointer to top of stack becse of inbuilt functions
	vector<T> a;	

public: 
	void push(T data){
		a.push_back(data);
	}

	void pop(){
		if(!isEmpty())
			a.pop_back();
	}

	T top(){
		// if(!isEmpty())
			return a[a.size()-1];
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

stack<string> stk;
// stack<char> stk;
int choice;
string s;
// char s;
do{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. push"<<endl;
	cout<<"2. pop"<<endl;
	cout<<"3. get top"<<endl;
	cout<<"4. print"<<endl;
	cout<<"5. exit"<<endl;

	cin>>choice;
	switch (choice){
		case 1: 
				cin>>s;
				stk.push(s);
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