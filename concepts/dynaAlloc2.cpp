/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 june 2019
AIM    : dynamic alloctaion of 2D arrays
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int **arr = new int*[3];	// allocate primary array of pointers to secondary arrays

for(int i=0; i<3; i++){		// allocate secondary arrays and store their adress in the primary array
	arr[i] = new int[4];
}

int counter=0;			
for(int i=0; i<3; i++){		// initialise the 2D array
	for(int j=0; j<4;j++){
		arr[i][j] = counter++;
	}
}

for(int i=0; i<3; i++){		// print the 2D array
	for(int j=0; j<4;j++){
		cout<<arr[i][j]<<endl;
	}
}

for(int i=0; i<3; i++){		// free up secondary arrays
	delete [] arr[i];
}
delete [] arr;				// free up primary array
cout<<"successfuly deleted memory"<<endl;

return 0;
}