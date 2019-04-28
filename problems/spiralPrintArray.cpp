/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 april 2019
AIM    : to print an array spirally starting for top left
STATUS :
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

void spiralPrint(int matrix[][10], int r, int c){
  int startRow=0, endRow=r-1;
  int startCol=0, endCol=c-1;

  while(startRow<=endRow && startCol<=endCol){
    // print the upper wall of the spiral
    for(int j=startCol; j<=endCol; j++)
          cout<<matrix[startRow][j]<<" ";
    startRow++;

    // print the right wall of the spiral
    for(int i=startRow; i<=endRow; i++)
      cout<<matrix[i][endCol]<<" ";
    endCol--;

    // print the bottom wall of the spiral
    for(int j=endCol; j>=startCol; j--)
      cout<<matrix[endRow][j]<<" ";
    endRow--;

    // print the left wall of the spiral
    for(int i=endRow; i>=startRow; i--)
      cout<<matrix[i][startCol]<<" ";
    startCol++;
  }
}

int main(){

int matrix[10][10], r, c;
cin>>r>>c;

readMatrix(matrix, r, c);
printMatrix(matrix, r, c);
spiralPrint(matrix, r, c);

return 0;
}
