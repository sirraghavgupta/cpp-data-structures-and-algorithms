/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 july 2019
AIM    : CPP program to count words in a string using stringstream. 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h> 
using namespace std; 

int countWords(string str) 
{ 
	// breaking input into word using string stream 
	stringstream s(str); // Used for breaking words 
	string word; // to store individual words 

	int count = 0; 
	while (s >> word) 
		count++; 
	return count; 
} 

// Driver code 
int main() 
{ 
	string s = "geeks for geeks geeks " "contribution placements"; 
	   // !!!! +++++ important to learn - the style of string initialization here +++++ !!!!
	cout<<s<<endl;
	cout << "Number of words are: " <<countWords(s)<<endl; 
	return 0; 
} 
