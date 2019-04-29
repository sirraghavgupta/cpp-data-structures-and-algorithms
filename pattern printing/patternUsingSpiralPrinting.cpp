/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 april 2019
AIM    : to print the following pattern by using spiralPrint algorithm
          00000
          0xxx0
          0x0x0
          0xxx0
          00000
         pattern of alternate rectangles of 0s and Xs
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

void spiralPatternPrint(char matrix[][10], int r, int c){

  // modified " s p i r a l P r i n t " algorithm

  int startRow=0, endRow=r-1;
  int startCol=0, endCol=c-1;
  char ch;
  int count=0;


  while(startRow<=endRow && startCol<=endCol){
    ch=(count&1)?'X':'0';         // to toggle charcater in alternate  rectangles

    // print the upper wall of the spiral
    for(int j=startCol; j<=endCol; j++)
          matrix[startRow][j]=ch;
    startRow++;

    // print the right wall of the spiral
    for(int i=startRow; i<=endRow; i++)
      matrix[i][endCol]=ch;
    endCol--;

    // print the bottom wall of the spiral
    if(endRow>=startRow){
      for(int j=endCol; j>=startCol; j--)
        matrix[endRow][j]=ch;
      }
    endRow--;

    // print the left wall of the spiral
    if(endCol>=startCol){
      for(int i=endRow; i>=startRow; i--)
        matrix[i][startCol]=ch;
      }
      startCol++;

    count++;
  }
}

int main(){

  char matrix[10][10];              // to hold the pattern
  int r, c;
  cin>>r;
  c=r;            // rows and columns should be same

  spiralPatternPrint(matrix,r,c);

  //print the matrix
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cout<<matrix[i][j];
    }
    cout<<endl;
  }

return 0;
}
