/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : to study about 2d arrays
STATUS :
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

// int arr[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
/* we have given the number of cols to be 4. so, it will automatically
take 4 values into a row and make the array accordingly.
now, if i give less than 16 values, it will take others to be 0.
and, if i give more than 16 values, it will  give error.
      ------------ s e e     b e l o w ----------*/
// int arr[4][4] = {1,2,3,4,5,6,7,8,9,10};


// int arr[][4] = {1,2,3,4,5,6,7,8};
/* here, it doesnt know the number of rows but know cols. so, its picking up
4-4 values and making as many rows it can.
now, if u will give 10 values, it will make 3 rows and fill remainig values
with 0
        --------------  s e e    b e l o w   -----------------  */
// int arr[][4] = {1,2,3,4,5,6,7,8,9,10};

/*for(int i=0; i<2; i++){        // to print the integer arrays
  for(int j=0; j<3; j++){
    cout<<arr[i][j]<<" ";
  }
  cout<<endl;
}*/


// ================= C H A R A C T E R   A R R A Y S ==================




// char arr[][3] = {{'a','b','c'}, {'d','e','f'}};    // initialise row by row
// char arr[][3] = {'a','b','c','d','e','f'};
// cout<<arr[0]<<endl;    // prints untill it gets a null
/* arr[0] is the address of the 0th row which is a char array.
and, whenever cout gets the address of a char array, it keeps printing
untill it gets a null. so, u can see.*/
// cout<<arr[1]<<endl;    // prints untill it  gets a null


// char arr[][4] = {{'a','b','c'},{'d','e','f'}};
/* in the remaining locations it may take null or may take grabage,
so, its always better to terminate every row by null char like below*/

// char arr[][4] = {{'a','b','c','\0'},{'d','e','f','\0'}};
// cout<<arr[0]<<endl;
// cout<<arr[1]<<endl;


return 0;
}
