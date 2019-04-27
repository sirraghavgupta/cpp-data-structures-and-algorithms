/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2018
AIM    : to generate all possible substrings out of a given string
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

char str[10];
cin>>str;

for(int i=0; str[i]!='\0';i++){     // define the startig index of the sub string
  for(int j=i; str[j]!='\0'; j++){  // define the ending index of the sub string
    for(int k=i; k<=j;k++){  // print the substrings
      cout<<str[k];
    }
    cout<<endl;
  }
}

return 0;
}
