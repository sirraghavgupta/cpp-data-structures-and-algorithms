/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 july 2019
AIM    : Replace all occurrences of pi with 3.14
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

char* replaceAllPIS(char *inp, int i, char*out, int j){
	// base case
	if(inp[i]=='\0'){
		out[j]='\0';
		return out;
	}

	// Rec case
	if(inp[i]=='p' && inp[i+1]=='i'){		
		out[j++]='3';
		out[j++]='.';
		out[j++]='1';
		out[j++]='4';
		i+=2;				
	}
	else{						
		out[j++]=inp[i++];
	}
	return replaceAllPIS(inp, i, out, j);	// next rec call
}

int main(){

int t;
cin>>t;

while(t>0){
	char inp[1001], out[2001];
	cin>>inp;
	replaceAllPIS(inp, 0, out, 0);
	cout<<out<<endl;
t--;
}

return 0;
}