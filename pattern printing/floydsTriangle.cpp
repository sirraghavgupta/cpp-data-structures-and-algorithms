/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to print floyd;s triangle
		 1
		 2 3
		 4 5 6
		 7 8 9 10
		 11 12 13 14
		 15 16 17 18 19
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int val=1;
for(int i=1; i<=n; i++){
	for(int j=0; j<i; j++ ){
		cout<<val++<<" ";
	}
	cout<<endl;
}

return 0;
}