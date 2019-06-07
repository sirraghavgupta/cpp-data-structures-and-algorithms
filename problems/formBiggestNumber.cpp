/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 june 2019
AIM    : You are provided an array of numbers. You need to arrange them in a way 
		 that yields the largest value.
		 example: 
		 54 546 548 60  ==>  6054854654
STATUS :
##############################################################################*/
#include <iostream>
#include <string.h>
using namespace std;

void stringSort(char arr[][7], int n){
  // ----------- using bubble sort ---------
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      char temp[100];
      if(strcmp(arr[i],arr[j])<0){
        strcpy(temp,arr[j]);
        strcpy(arr[j],arr[i]);
        strcpy(arr[i],temp);
      }
    }
  }
}

int main(){


int t;
cin>>t;

while(t>0){
	
	int n;
	cin>>n;
	char str[n][7];
	// read the numbers in form of string
	for(int i=0; i<n; i++){
		cin>>str[i];
	}

	stringSort(str, n);
	// display the output
	for(int i=0; i<n; i++){
		cout<<str[i];
	}
	cout<<endl;	
t--;
}

return 0;
}