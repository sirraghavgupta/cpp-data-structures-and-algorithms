/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : Given coefficients of a quadratic equation , you need to print the 
		 nature of the roots (real and distinct , real and equal , imaginary) 
		 and the roots also
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){

int a, b, c;
cin>>a>>b>>c;		// read coefficients

int b2 = b*b, ac4=4*a*c;	// b sqare and 4ac

// detect nature of roots
if(b2>ac4)	cout<<"Real and Distinct"<<endl;
else if(b2 == ac4)	cout<<"Real and Equal"<<endl;
else cout<<"Imaginary"<<endl;

// print roots if they exist
if(b2>=ac4){
	double d=sqrt(b2-ac4);
	int root1 = (-b+d)/2*a;
	int root2 = (-b-d)/2*a;

cout<<min(root1, root2)<<" "<<max(root1, root2)<<endl;

}

return 0;
}