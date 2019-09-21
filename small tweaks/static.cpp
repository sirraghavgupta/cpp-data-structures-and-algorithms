/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 september 2019
AIM    : testing static variable
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int fun(){
	static int x = 5;
	if(x>10)
		x=15;
	return x++;
}

int main(){

cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;
cout<<fun()<<endl;

return 0;
}