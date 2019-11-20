// C++ program to demonstrate static 
// variables inside a class 

#include<iostream> 
using namespace std; 

/*class GfG 
{ 
public: 
	static int i; 
	
	GfG() 
	{ 
		// Do nothing 
      cout<<this::i<<endl;
	}; 
	void stat(){
		// cout<<GFGi<<endl;
		i++;
	}
  
}; */

class test{
public:
	static int c;
	static void show(){
		cout<<"i am aa static function"<<endl;
		cout<<test::c<<endl;
	}
};

int main(){

test t;
test::show(); 
// cout<<test::c<<endl;
} 
