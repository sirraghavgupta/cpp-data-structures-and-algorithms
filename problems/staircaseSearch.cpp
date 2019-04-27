/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : to search a value in a 2d array which is sorted along the rows as
         well as sorted along the columns.
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



int main(){

  int matrix[10][10], r, c;
  cin>>r>>c;

  readMatrix(matrix, r, c);


return 0;
}
