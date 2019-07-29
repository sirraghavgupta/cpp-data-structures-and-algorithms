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

float arr[n];
float cumm[n];

for(int i=0; i<n; i++){
	cin>>arr[i];
}

cumm[n-1] = arr[n-1];
for(int i=n-2; i>=0; i--){
	cumm[i] = cumm[i+1] + arr[i];
}


// for(int i=0; i<n; i++){
// 	cout<<arr[i]<<"  ";
// }
// cout<<endl;

// for(int i=0; i<n; i++){
// 	cout<<cumm[i]<<"  ";


// }
// cout<<endl;

float max = cumm[0];

for(int i=n-1; i>=0; i--){
	float sum = (max-cumm[i]);
	// cout<<sum<<endl;
	if(cumm[i]>=sum){
		cout<<n-i<<endl;
		break;
	}
}

return 0;
}

