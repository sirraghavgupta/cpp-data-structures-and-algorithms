/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 june 2019
AIM    : 
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

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
		v[i].push_back(str);
		cin.get(ch);
	}while(ch!='\n');
}

int key;			// which column to sort on behalf of
string pattern;		// lexicographic or numeric	
string reverse;		// reverse or forward

cin>>key;
// cin>>pattern;
// cin>>reverse;

// sorting logic ================================

  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      string temp;;
      if(strcmp(v[i].at(key-1),v[j].at(key-1))>0)
      	swap(v[j][key-1],v[i][key-1]);
  }
}

// if(pattern=="lexicographical"){
// 	if(reverse=="false")
// 		sort(v, v+n, compare);
// 	else
// 		sort(v, v+n, compare);
// }	
// else{

// }



// print the data 
for(int i=0; i<n; i++){
	for(int j=0; j<v[i].size(); j++){
		cout<<v[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}