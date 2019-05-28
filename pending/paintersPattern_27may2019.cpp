/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 May 2019
AIM    : 
STATUS :
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(int a, int b){
	return a>b;
}

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){

int n,k; 	// k = number of painters
			// n = number of boards to be painted
cin>>k>>n;
int boards[n];	// hold the size of n boards
int painters[k];	
int totalTime=0;	// minimum time required to paint all the boards

for(int i=0; i<n;i++){	// read the board sizes
	cin>>boards[i];
}

for(int i=0; i<k; i++){	// initialise painters array to 0
	painters[i]=0;
}

printArray(boards, n);
sort(boards,boards+n, comparator);
cout<<"sorted array"<<endl;
printArray(boards,n);

// job allocation

int count=0;
while(count<k){
	
	painters[count]=boards[count];
	count++;
}
while(){
	painters[count]=boards[3-count%3];
}

return 0;
}