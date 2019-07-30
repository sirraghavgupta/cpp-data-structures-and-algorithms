/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : learn to use scanf function
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

// this function is used to read input from strings --- very nice

int main(){

char s[100];
cin>>s;

int num;
sscanf(s, "%d", &num);
cout<<num<<endl;

char str[100] = "raghav has 3 blue balls";
char s1[50], s2[50];
// %*s is used to skip a word 
sscanf(str, "%s %*s %d %*s %s", s1, &num, s2);
cout<<s1<<endl;
cout<<num<<endl;
cout<<s2<<endl;
cout<<str<<endl;	// string also persists the data

return 0;
}