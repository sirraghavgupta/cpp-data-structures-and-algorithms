/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 23 May 2019
AIM    : sort n strings lexicographically but if two strings have a common beginning
		 then the bigger string should come first
STATUS : !!! success !!! according to portal
		 but .........
		 according to me the output should be more refined later on
##############################################################################*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool comparator(string s1, string s2){
	if(s1[0]==s2[0]) 		// if first character is same, then sort according to length
		return s1.length() > s2.length();
	else 					// else sort lexicographically
		return s1<s2;
}

int main(){

int n; 		// number of strings
cin>>n;

string str[n]; 		// string array

for(int i=0; i<n; i++){ 	// input strings
	cin>>str[i];
}

sort(str, str+n, comparator);

for(int i=0; i<n; i++){ 	// display sorted strings
	cout<<str[i]<<endl;
}

return 0;
}