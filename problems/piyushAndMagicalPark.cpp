/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : see the photograph of problem
STATUS : !!! success !!!

---- meaning less question for me ----------
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int m,n,k,s;
cin>>m>>n>>k>>s;	// m rows, n columns, k is min strength req, s is the initial strength

int arr[m][n];		
char ch;
int totalSum=s;		// it stores the total strength piyush can gather in the park
					// he has some initial, plus we add the values of all the characters 
					// irrespective of whether he would reach them or not because of #

// i am not storing the charcaters in the array, instead i am storing their profits\ values.
for(int i=0; i<m; i++){
	for(int j=0; j<n; j++){
		cin>>ch;		// input char and check it
		if(ch=='.')		arr[i][j]=-3;
		else if(ch=='*')	arr[i][j]=4;
		else	arr[i][j]=0;	
		totalSum+=arr[i][j];		// add strength to the totalSum.
	}
}

// processing for possibility of coming out
for(int i=0; i<m; i++){
	for(int j=0; j<n; j++){
		if(s>=k){	// proceed only if u have strength
			if(arr[i][j]==0)	// if hash encoutered, go to the next row i.e. in the parent loop
				break;
			else{				// else adjust the strength
				s+=arr[i][j];
			}
		}
		else{		// if u dont have strength, u can tell NO
			cout<<"No"<<endl;
			// cout<<totalSum<<endl;
			return 0;
		}
	}
}
cout<<"Yes"<<endl;
cout<<totalSum<<endl;

return 0;
}