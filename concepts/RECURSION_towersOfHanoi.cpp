/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 june 2019
AIM    : to solve the tower of hanoi problem using recursion
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;
// int count=0;		// to count the total number of steps. 
void towersOfHanoi(int n, char src, char dest, char helper){
	if(n==0)
		return;
	towersOfHanoi(n-1, src, helper, dest);
	cout<<"move "<<n<<" disc from "<<src<<" to "<<dest<<endl;
	// count++;
	towersOfHanoi(n-1, helper, dest, src);
}

int main(){

int n;
cin>>n;
towersOfHanoi(n, 'A', 'C', 'B');
// cout<<count<<endl;

return 0;
}