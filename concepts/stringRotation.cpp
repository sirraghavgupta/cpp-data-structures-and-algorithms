/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 april 2019
AIM    : to rotate a string by k characters
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){

char str[50];
int k;

cout<<"!! ------ enter a string of size smaller than 25 : "<<endl;
cin.getline(str, 24);
int len = strlen(str);
cout<<"enter the value of k: ";
cin>>k;

// shifting the characters of string by k characters from the back
for(int i=len; i>=0; i--){
  str[i+k]=str[i];
}
// cout<<str<<endl;       // verify the shifting operation


// rotation logic - copy the last k chars to the beginning
for(int i=len; i<len+k; i++){
  str[i-len]=str[i];
}
str[len]='\0';  // terminate the string at the original length
cout<<str<<endl;

return 0;
}
