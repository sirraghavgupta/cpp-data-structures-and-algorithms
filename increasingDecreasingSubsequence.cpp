/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : june 2019
AIM    : Take the following as input.
		 A number (N)
		 Take N more numerical inputs
		 The N inputs for a sequence S = s1, s2, .., sN. Compute if it is possible 
		 to split sequence into two sequences - s1 to si and si+1 to sN such that 
		 first sequence is strictly decreasing and second is strictly increasing. 
		 Print true/false as output.
STATUS : !!! needs to be optimised !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;		// size of array
cin>>n;

int arr[n];		// read array
for(int i=0; i<n; i++)
	cin>>arr[i];
		
int flag=0;			// dereasing sequence
for(int i=0; i<n; i++){
	if(!flag){
		if(arr[i]>arr[i+1])
			continue;
		else{
			flag++;
			// i--;
		}

	}

	else if(flag==1){
		if(arr[i]<arr[i+1])	
			continue;
		else 
			flag++;
	}
	else{
		cout<<"false"<<endl;
		return 0;
	}
}
cout<<"true"<<endl;
return 0;
}