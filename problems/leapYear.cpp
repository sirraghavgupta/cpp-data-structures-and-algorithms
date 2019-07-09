/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 july 2019
AIM    : to check whether a year is leap or not
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool checkYear(int year){
	return ((year%400 == 0)||((year%4 == 0) && (year%100 !=0)));
}

int main(){

	int year;
	cin>>year;
	checkYear(year)?cout<<"leap year"<<endl:cout<<"non leap year"<<endl;
return 0;
}