/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : Take as input S, a string. Write a function that returns the character 
		 with maximum frequency. Print the value returned.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

char maxFrequentCharacter(char *str){
	int length = strlen(str);	// get length of string
	int frequency[26]={0};

	for(int i=0; i<length; i++){	// counting of characters 
		frequency[str[i]-'a']++;
	}

	int max=0;
	for(int i=0; i<26; i++){
		if(frequency[i]>frequency[max])	max=i;
	}

	return char(max+97);
}

int main(){

char str[1001];		// get string
cin>>str;

cout<<maxFrequentCharacter(str)<<endl;	
}