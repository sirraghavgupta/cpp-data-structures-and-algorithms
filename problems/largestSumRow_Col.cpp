/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : to find the row or column with largest sum in the 2D array.
STATUS : !!! success !!!
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

void maxSumRowCol(int matrix[][10], int r, int c){
  int maxSum=0, currSum;
  int rowOrCol=-1, index=-1;       // rowCol = 0 for rows and 1 for columns
                                   // index shows the number of the row/ column

  // evaluate max sum for rows
  for(int i=0; i<r; i++){
    currSum=0;
    for(int j=0; j<c; j++){
      currSum+=matrix[i][j];
    }
    if(currSum>maxSum){
      maxSum=currSum;
      index=i;
      rowOrCol=0;
    }
  }

  // evaluate max sum for columns
  for(int j=0; j<r; j++){
    currSum=0;
    for(int i=0; i<c; i++){
      currSum+=matrix[i][j];
    }
    if(currSum>maxSum){
      maxSum=currSum;
      index=j;
      rowOrCol=1;
    }
  }

// print the output that WHICH row/ col, index, what maxSum
if(!rowOrCol)
    cout<<"row "<<index<<" is having maximum sum of: "<<maxSum<<endl;
else
    cout<<"column "<<index<<" is having maximum sum of: "<<maxSum<<endl;

return;
}

int main(){

  int matrix[10][10], r, c;
  cin>>r>>c;

  readMatrix(matrix, r, c);
  printMatrix(matrix, r, c);
  maxSumRowCol(matrix, r, c);

return 0;
}
