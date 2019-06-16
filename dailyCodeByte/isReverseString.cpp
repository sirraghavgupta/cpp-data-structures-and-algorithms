/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 june 2019
AIM    : to check whether a string is reverse of another or not
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isReverse(string s1, string s2){
	reverse(s1.begin(), s1.end());
	if(s1==s2)	return true;
	else return false;
}

int main(){

string s1, s2;
cin>>s1;
cin>>s2;

isReverse(s1, s2)?cout<<"true"<<endl:cout<<"false"<<endl;	

return 0;
}