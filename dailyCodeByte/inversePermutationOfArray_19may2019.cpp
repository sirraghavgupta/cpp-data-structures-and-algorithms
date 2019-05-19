/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 may 2019
AIM    : to find the inverse permutation of an array
	   : inverse permutation means insert the index of element at the position
	     specified by the value of the element. in this way, create a new array.
	     example - 2 3 4 5 1
	     inverse - 5 1 2 3 4
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int n; 			// size of array
cin>>n;

int arr[100000]; 	// original array
int inverse[100000]={0}; 	// inverse array

for(int i=0; i<n; i++){		
	cin>>arr[i];			// input element 
	inverse[arr[i]]=i;		// insert element in inverse array
	// cout<<inverse[i]<<endl; 		// print the inverted array
		/* ----- i cant print here because it will print the element which is not yet generated
	 so, i will get wrong output. because elements are not generated in sequnetial order here*/
}

for(int i=0; i<n; i++){ 	// print the inverted array
	cout<<inverse[i]<<endl;
}


return 0;
}