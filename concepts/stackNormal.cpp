/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 october 2019
AIM    : to implement the stack data structure using array without any class
		 or structure 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

// bool isEmpty(int top){
// 	return top<0;
// }

// bool isFull(int top, int size){
// 	return top==size-1;
// }

int getTop(int arr[], int top){
	if(top>=0)
		return arr[top];
	else
		cout<<"stack empty"<<endl;
	return -99999999;
}

void pop(int arr[], int &top){
	if(top>=0)
		top--;
	else
		cout<<"stack empty"<<endl;
}

void push(int arr[], int size, int &top, int data){
	if(top<size-1){
		top++;
		arr[top] = data;
	}
	else{
		cout<<"stack already full"<<endl;
	}
}

void print(int arr[], int top){
	for(int i=top; i>=0; i--){
		cout<<arr[i]<<endl;
	}
}

int main(){

int stk[20];

int size;	// usable size of stack 
cin>>size;

int top = -1;


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
				push(stk, size, top, data);
				break;
		case 2: pop(stk, top);
				break;
		case 3:	cout<<getTop(stk, top)<<endl;
				break;
		case 4: print(stk, top);
				break;
		case 5: exit(0);
		default: cout<<"invalid input"<<endl;
				break;
	}

}while(choice!=0);

return 0;
}