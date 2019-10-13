/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 october 2019
AIM    : You are provided an array of numbers. You need to arrange them in a 
		 way that yields the largest value.
		 like 54 546 548 60 => 6054854654
		 like 1 34 3 98 9 76 45 4 => 998764543431
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
	// tricky - this is awesome
	string s = a+b;
	string t = b+a;
	return s>t;
	/*
	if i arrange only in reverse lexicographic order, then there will be problem
	9 98 => 98 9 while bigger number is possible by 9 98 
	so, i feel that i should find substring and print the smaller one first

	but there is another issue
	5 54 => 5 54	// works fine
	5 56 => 5 56    // doesnt work fine

	because we have to see if the part after the common part is bigger than the common
	part or not. 
	so we check both the possible combinations and return accordingly.
	so, basically we are checking for every 2 strings that which combination will 
	give ideal result. now we dont care about lexico order or length or whatever. 
	great!!! 
	*/
}

int main(){

int t;
cin>>t;

while(t--){
	int n;
	cin>>n;

	string num[n];
	for(int i=0; i<n; i++){
		cin>>num[i];
	}

	sort(num, num+n,compare);

	for(int i=0; i<n; i++){
		cout<<num[i];
	}
	cout<<endl;

}


return 0;
}