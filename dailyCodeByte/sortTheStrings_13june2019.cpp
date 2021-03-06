/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 june 2019
AIM    : see in the image
STATUS : !!! failing test cases !!!
NOTE   : not running on THIS compiler due to stoi. run on ide..
##############################################################################*/

#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2, bool pattern, bool rev){
	if(pattern){		// lexicographic sort
		if(rev)
			return s1>s2; 
		else
			return s1<s2;		
	}
	else{				// numeric sort
		if(rev)
			return stoi(s1)<stoi(s2);
		else
			return stoi(s1)>stoi(s2);
	}							
}

void Sort(vector<string> v[10], int n, int key, bool rev, bool pattern){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
      if(compare(v[j][key-1], v[j+1][key-1], pattern, rev))
      	swap(v[j],v[j+1]);
  	}
 }

}

int main(){

int n;
cin>>n;

vector<string> v[n];
string str;

// read the data
for(int i=0; i<n; i++){

	char ch;
	do{
		cin>>str;
		str.shrink_to_fit();
		v[i].push_back(str);
		cin.get(ch);
	}while(ch!='\n');
	v[i].shrink_to_fit();
}

int key;			// which column to sort on behalf of
string input;		
bool pattern;
bool rev;

cin>>key;

cin>>input;
rev=(input=="true")?1:0;

cin>>input;
pattern=(input=="lexicographical")?1:0;

// sorting logic ================================
Sort(v, n, key, rev, pattern);


// print the data 
for(int i=0; i<n; i++){
	for(int j=0; j<v[i].size(); j++){
		cout<<v[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}