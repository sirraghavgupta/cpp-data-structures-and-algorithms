/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 june 2019
AIM    : to rotate an nXn matrix image by 90 degree anticlockwise
STATUS : !!! success !!!
space complexity : O(1) --- constant space
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int matrix[n][n];

// read the matrix
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		cin>>matrix[i][j];
	}
}

// rotation of matrix

// flip first about the top left to bottom right diagonal
for(int i=0; i<n; i++){
	for(int j=0; j<i; j++){ 		
						// we need t operate on only on one side of the diagonal, else the
						// resultant matrix will be the same as previous due to double swap
		int temp;
		temp = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = temp;
	}
}

// reverse the columns 
for(int j=0; j<n; j++){
	for(int i=0; i<n/2; i++){	// operate on half row only  --- reason same as above
		int temp;
		temp = matrix[i][j];
		matrix[i][j] =matrix[n-i-1][j];
		matrix[n-i-1][j] = temp;
	}
}

// print the matrix
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		cout<<matrix[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}