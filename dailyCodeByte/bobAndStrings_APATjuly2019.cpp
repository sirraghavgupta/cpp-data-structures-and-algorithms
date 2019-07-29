/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : to find the difference between the max freq and min freq of any char in 
		 given string --- see screenshot.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){

string s;
cin>>s;

int arr[26] = {0};

for(int i=0; i<s.length(); i++){
	int index = s[i] - 'a';
	arr[index]++;
}

// for(int i=0; i<26; i++){
// 	cout<<arr[i]<<" ";
// }
// cout<<endl;

int min=1, max=1;
for(int i=0; i<26;  i++){
	if(arr[i]<min and arr[i]>0)
		min=arr[i];
	if(arr[i]>max)
		max=arr[i];
}
cout<<max-min<<endl;
return 0;
}