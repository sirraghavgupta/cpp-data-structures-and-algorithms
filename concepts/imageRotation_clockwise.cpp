/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 may 2019
AIM    : to rotate a square image by 90 degrees clockwise in O(1) namespace
        so, basically we have to do INPLACE rotation here.
STATUS : !!! success !!!
space complexity : O(1) --- constant space
##############################################################################*/
#include <iostream>
using namespace std;

void readMatrix(int matrix[][10], int r, int c){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin>>matrix[i][j];
    }
  }
}

void printMatrix(int matrix[][10], int r, int c){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
}

void rotateMatrix(int matrix[][10], int n){

// logic behind rotation is flip it diagonally first and then reverse the rows.

  int temp;
  // flip the matrix
    for(int i=0; i<n; i++){
      /* we need to operate only on left half of the matrix w.r.t. the top left
      to bottom right wali diagonal.
      else, the matrix will be flipped twice and we'll be having the same matrix
      again */
      for(int j=0; j<i; j++){
          temp=matrix[i][j];
          matrix[i][j]=matrix[j][i];
          matrix[j][i]=temp;
      }
    }

  // reverse the rows
   for(int i=0; i<n;i++){
     // operate only on half of the row, else u will have the same row again
     for(int j=0; j<n/2; j++){
       temp=matrix[i][j];
       matrix[i][j]=matrix[i][n-j-1];
       matrix[i][n-j-1]=temp;
     }
   }
}

int main(){

int image[10][10];
int n;      // dimension of the square matrix
cin>>n;

readMatrix(image,n,n);
rotateMatrix(image,n);
printMatrix(image,n,n);
return 0;
}
