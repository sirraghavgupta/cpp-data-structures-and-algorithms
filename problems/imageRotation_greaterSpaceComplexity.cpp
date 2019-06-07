/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 june 2019
AIM    : to rotate an nXn matrix image by 90 degree anticlockwise
STATUS : !!! success !!!
space complexity : O(n)
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
int rotated[n][n];
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		rotated[i][j] = matrix[j][n-i-1];
	}
}

//copy the rotated matrix into the original matrix
for(int i=0; i<n; i++){
	for(int j=0; j<n; j++)
		matrix[i][j] = rotated[i][j];
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