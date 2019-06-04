/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 june 2019
AIM    : to demonstrate the concept of dynamic memory allocation
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int *a = new int;		// assigns a random value to this
int *b = new int(30);	// initialise with 30
// int *c = new int;
int *arr = new int[10]; // an integer array of 10 memory locations

cout<<*a<<endl;
cout<<*b<<endl;
// cout<<*c<<endl;

for(int i=0; i<10; i++){	// initialise the array = same as static
	arr[i]=i;
}

for(int i=0; i<10; i++){	// print the array = same as static
	cout<<arr[i]<<" ";
}
cout<<endl;

// free the heap memory
delete a;
delete b;
delete arr; 	//---- !!! W R O N G !!! ----
delete [] arr;		// very important to write []
cout<<"success deletion"<<endl;
return 0;
}