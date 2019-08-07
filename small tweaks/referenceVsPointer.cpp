/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : study and differentiate between references and pointers in c
STATUS : !!! success !!! --- very nice n important
##############################################################################*/
 
/*
	In C++, we can pass parameters to a function either by pointers or by reference. 
	In both the cases, we get the same result. So the following questions are inevitable; 
	when is one preferred over the other? What are the reasons we use one over the other?

	Difference in Reference variable and pointer variable -->
	* References are generally implemented using pointers. A reference is same object, 
	  just with a different name and reference must refer to an object. Since references 
	  can’t be NULL, they are safer to use.

	* A pointer can be re-assigned while reference cannot, and must be assigned at 
	  initialization only.
	* Pointer can be assigned NULL directly, whereas reference cannot.
	* Pointers can iterate over an array, we can use ++ to go to the next item that a 
	  pointer is pointing to.
	* A pointer is a variable that holds a memory address. A reference has the same memory 
	  address as the item it references.
	* A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a 
	  reference uses a ‘.'(dot operator)
	* A pointer needs to be dereferenced with * to access the memory location it points to, 
	  whereas a reference can be used directly.
*/

#include <iostream> 
using namespace std; 

struct demo 
{ 
	int a; 
}; 

int main() 
{ 
	int x = 5; 
	int y = 6; 
	demo d; 
	
	int *p; 
	p = &x; 
	p = &y;					 // 1. Pointer reintialization allowed 
	int &r = x; 
	// &r = y;				 // 1. Compile Error 
	r = y;					 // 1. x value becomes 6 
	
	p = NULL;		 
	// &r = NULL;			 // 2. Compile Error 
	
	cout<<&p<<endl;
	p++;					 // 3. Points to next memory location 
	r++;					 // 3. x values becomes 7 
	
	cout << &p << " " << &x << endl; // 4. Different address 
	cout << &r << " " << &x << endl; // 4. Same address 
	
	demo *q = &d; 
	demo &qq = d; 
	
	q->a = 8; 
	// q.a = 8;				 // 5. Compile Error 
	qq.a = 8; 
	// qq->a = 8;			 // 5. Compile Error 
	
	cout << p << endl;	 // 6. Prints the address 
	cout << r << endl;	 // 6. Print the value of x	 

	return 0; 
} 


