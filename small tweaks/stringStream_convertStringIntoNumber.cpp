/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : convert string into number using string stream
STATUS : !!! awesome success !!!
##############################################################################*/

#include <iostream>
#include <sstream>
using namespace std;

int convertToInt(string str){

	stringstream s(str);
	int num = 0;

	s>>num;
	return num;
}

float convertToFloat(string str){
	stringstream s(str);
	float num = 0;

	s>>num;
	return num;	
}

int main(){

string str;
cin>>str;
int num = convertToInt(str);
float n = convertToFloat(str);
cout<<num<<endl;
cout<<n<<endl;

return 0;
}