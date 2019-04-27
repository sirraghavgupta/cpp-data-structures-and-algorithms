/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : to read and print a matrix
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

int main(){

int matrix[10][10], r, c;
cin>>r>>c;

readMatrix(matrix, r, c);
printMatrix(matrix, r, c);

return 0;
}
