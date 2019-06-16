/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 june 2019
AIM    : see in the image
STATUS : -- logic is fine... some modification is required
##############################################################################*/

#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

bool compare(int n1, int n2, bool pattern, bool rev){
	if(pattern){		// lexicographic sort
		if(rev)
			return to_string(n1)<to_string(n2); 
		else
			return to_string(n1)>to_string(n2);		
	}
	else{				// numeric sort
		if(rev)
			return n1<n2;
		else
			return n1>n2;
	}							
}

void Sort(vector<int> v[10], int n, int key, bool rev, bool pattern){
  for(int i=0; i<n-1; i++){
    for(int j=0; j<n-i-1; j++){
      int temp;
      if(compare(v[j][key-1], v[j+1][key-1], pattern, rev))
      	swap(v[j],v[j+1]);
  	}
 }

}

int main(){

int n;
cin>>n;

vector<int> v[n];
int num;

// read the data
for(int i=0; i<n; i++){

	char ch;
	do{
		cin>>num;
		v[i].push_back(num);
		cin.get(ch);
	}while(ch!='\n');
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