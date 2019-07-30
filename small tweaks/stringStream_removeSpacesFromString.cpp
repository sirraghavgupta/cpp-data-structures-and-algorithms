/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : to remove spaces from string using string stream
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

void removeSpaces(string &str){
	stringstream s(str);
	str = "";
	string word;
	while(s>>word){
		str = str + word;
	}
	return;
}

int main(){

string str;
getline(cin, str);
removeSpaces(str);

cout<<str<<endl;
return 0;
}