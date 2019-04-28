/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : to print an array spirally starting for top left - ANTI CLOCKWISE
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

void initMatrix(int matrix[10][10], int r, int c){
  int value = 1;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      matrix[i][j]=value++;
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

void spiralPrint(int matrix[][10], int r, int c){
  int startRow=0, endRow=r-1;
  int startCol=0, endCol=c-1;

  while(startRow<=endRow && startCol<=endCol){

    // print the left wall of the spiral
      for(int i=startRow; i<=endRow; i++)
        cout<<matrix[i][startCol]<<" ";
      startCol++;

    // print the bottom wall of the spiral
      for(int j=startCol; j<=endCol; j++)
        cout<<matrix[endRow][j]<<" ";
      endRow--;

    // print the right wall of the spiral
    if(endCol>=startCol){
    for(int i=endRow; i>=startRow; i--)
      cout<<matrix[i][endCol]<<" ";
    }
    endCol--;

    // print the upper wall of the spiral
    if(endRow>=startRow){
    for(int j=endCol; j>=startCol; j--)
          cout<<matrix[startRow][j]<<" ";
    }
    startRow++;

  }
}

int main(){

int matrix[10][10], r, c;
cin>>r>>c;

// readMatrix(matrix, r, c);  // if u want to input your own matrix
initMatrix(matrix, r, c);     // get the default natural number matrix
printMatrix(matrix, r, c);
spiralPrint(matrix, r, c);

return 0;
}
