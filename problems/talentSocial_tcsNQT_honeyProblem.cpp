/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : 
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int a, b, c;
cin>>a>>b>>c;

if(n<1)
	return 0;

int ans=0;
int arr[4]={a, b, c, a};
int pos=0;
while(n>1){

	if(arr[pos+1]<arr[pos]){
		pos=(pos+1)%3;
		ans += arr[pos];
	}
	else{
		
		ans += arr[pos];
	}

	n--;
}

cout<<ans<<endl;
return 0;
}