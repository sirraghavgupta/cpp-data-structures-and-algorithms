/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2019
AIM    : input a character. print L if the charcater is lowercase, print U if the
         character is uppercase, else print I.
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cctype>  // for character handling in c++, special functions r there
using namespace std;

char checkCharType(char a){
  if(islower(a))   return 'L';
  else if(isupper(a))  return 'U';
  else  return 'I';
}
int main(){

char a;
cin>>a;
cout<<checkCharType(a);

return 0;
}
