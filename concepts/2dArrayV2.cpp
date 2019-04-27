/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : more about the 2D arrays
AIM    : 27 april 2019
STATUS : !!! how to sort this 2Darray !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

char fruits[10][100] = {"apple", "mango", "banana", "patata"};
/* initialise the arra with strings, no need to put null char explicitly.*/

// cout<<fruits[0]<<endl;
// cout<<fruits[1]<<endl;
// cout<<fruits[2]<<endl;
// cout<<fruits[3]<<endl;

cin>>fruits[4];
// cout<<fruits[4]<<endl;    // take string input into the array

fflush(stdin);
cin.getline(fruits[5],100);
// cout<<fruits[5]<<endl;


// print the fruits array
for(int i=0; i<10; i++){
  cout<<fruits[i]<<endl;
}
return 0;
}
