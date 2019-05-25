/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 May 2019
AIM    : to find total number of ways in which n friends can be paired.
		 any friend can be in atmost 1 pair only
		 friends can be unpaired also.
MY LOGIC:
		 so, basically go like - 
		 1. all are unpaired
		 2. only one pair is there and rest are unpaired
		 3. two pairs are there and rest are unpaired
		 4. by logic, u can have n/2 pairs at max.
STATUS : !!! logic not understood !!!
		 !!! BUT s u c c e s s !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int t;
cin>>t;

while(t>0){
	int n;	// number of friends
	cin>>n;

	unsigned long int result=1;	// total number of ways
	unsigned long int temp=1;
	int count=1;
	for(int i=n; i>=2; i-=2){
		temp*=i*(i-1)/2;
		temp/=count;
		result += temp;
		count++;
		// cout<<"temp = "<<temp<<endl;
		// cout<<"result = "<<result<<endl;
	}
	cout<<result<<endl;
	t--;
}

return 0;
}