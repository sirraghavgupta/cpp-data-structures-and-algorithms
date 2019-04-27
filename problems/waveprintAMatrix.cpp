/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : print a matrix in wave form starting from top left, up down up down manner
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

void wavePrint(int matrix[][10], int r, int c){
  // -------------- W A V E  P R I N T I N  G ---------------

  for(int j=0; j<c; j++){   // print col by col
    if(j&1){     // if j is odd = odd col
      // print bottom up
      for(int i=r-1; i>=0; i--)
            cout<<matrix[i][j]<<" ";
    }
    else{        // j is even = even col
      // print top down
      for(int i=0; i<=r-1; i++)
            cout<<matrix[i][j]<<" ";
    }
  }
}

int main(){

int matrix[10][10], r, c;
cin>>r>>c;

readMatrix(matrix, r, c);
printMatrix(matrix, r, c);
cout<<endl<<"wave printing ---------------- "<<endl;
wavePrint(matrix, r, c);

return 0;
}
