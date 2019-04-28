/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : to search a value in a 2d array which is sorted along the rows as
         well as sorted along the columns.
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

void  bruteforceSearch(int matrix[][10], int r, int c, int key){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(key==matrix[i][j]){
        cout<<"value found at ("<<i<<","<<j<<")"<<endl;
        return;
      }
    }
  }
  cout<<"value not found"<<endl;
  return;
}

void staircaseSearch(int matrix[][10], int r, int c, int key){
//  -------------- S T A I R C A S E   S E A R C H ----------------

  int i=0, j=c-1;       // begin from top right corner
  while(i<=r && j>=0){  // terminate at bottom left corner, dont exit the matrix
    if(matrix[i][j]==key){     // value found
      cout<<"value found at ("<<i<<","<<j<<")"<<endl;
      return;
    }
    else if(key<matrix[i][j]){    // go to left
      j--;
    }
    else{                         // go down
      i++;
    }
  }
  cout<<"value not found"<<endl;
}

void customsearch(int matrix[][10], int r, int c, int key){

}

int main(){

  int matrix[10][10], r, c;
  cin>>r>>c;
  readMatrix(matrix, r, c);
  printMatrix(matrix, r, c);
  int key;
  cin>>key;

  // bruteforceSearch(matrix, r, c, key;    // for bruteforce search
  // staircaseSearch(matrix, r, c, key);    // for staircase search
  customsearch(matrix, r, c, key);    // for raghav made search


return 0;
}
