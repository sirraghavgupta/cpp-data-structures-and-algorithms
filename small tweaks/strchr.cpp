/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 august 2019
AIM    : to get the first occurence of a character in string
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){

char str[100];
cin>>str;

cout<<strchr(str, 'a')<<endl;
cout<<strchr(str, 'z')<<endl;

return 0;
}