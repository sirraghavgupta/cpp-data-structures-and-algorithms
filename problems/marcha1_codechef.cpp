/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 june 2019
AIM    : see image
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int getSum(int wallet[], int n, int mask){
	int sum=0;
	for(int i=0; i<n; i++){
		if(mask&1)
			sum+=wallet[i];
		mask = mask>>1;
	}
	return sum;
}

bool generateSubsets(int wallet[], int n, int demand){
	int range = (1<<n) - 1;
	for(int i=0; i<=range; i++){
		if(getSum(wallet, n, i)==demand)	return true;
	}
	return false;
}

int main(){

int t;
cin>>t;

int n, demand, wallet[20];
while(t>0){

	cin>>n;
	cin>>demand;
	for(int i=0; i<n; i++)
		cin>>wallet[i];

	generateSubsets(wallet, n, demand)?cout<<"yes"<<endl:cout<<"no"<<endl;

t--;
}


return 0;
}