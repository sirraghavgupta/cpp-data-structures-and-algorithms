/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : see photograph
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++)
	cin>>arr[i];

int q;
cin>>q;

int qtype, x, y;

for(int i=0; i<q; i++){
	cin>>qtype>>x>>y;
	int count;

	switch(qtype){

		case 0:	
				arr[x-1]=y;
				break;
		
		case 1: 
				count=0;
				for(int j=x-1; j<=y-1; j++){
					if(arr[j]%2==0)	count++;
				}
				cout<<count<<endl;
				break;
		
		case 2: 
				count=0;
				for(int j=x-1; j<=y-1; j++){
					if(arr[j]&1)	count++;
				}
				cout<<count<<endl;
				break;

	}
}
return 0;
}