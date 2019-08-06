/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 august 2019
AIM    : to find the length of longest substring which contains unique characters
STATUS : !!! success !!! --- very difficult
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){

char a[100];	
cin>>a;
int n = strlen(a);

int curr_len = 1;
int max_len = 1; 	// single char will always be the minimum string


int visited[256];
// each character is unvisited initially
// visited[] stores the last occurence of any character
for(int i=0; i<256; i++)
	visited[i] = -1;



// for first character
visited[a[0]] = 0;

// remaining string
for(int i=1; i<n; i++){
	int last_occ = visited[a[i]];

	// expansion case
	/* if current char has never occured or not present in the current window */
	if(last_occ==-1 || (last_occ<i-curr_len)){
		curr_len++;
	}

	// expansion + contraction case
	else{
		max_len = (curr_len>max_len)?curr_len:max_len;
		curr_len = i - last_occ;
	}
	
	visited[a[i]] = i;
}

max_len = (curr_len>max_len)?curr_len:max_len;

cout<<max_len<<endl;

return 0;
}