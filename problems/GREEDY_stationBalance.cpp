/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 october 2019
AIM    : see the doc with adobe reader
STATUS : !!! correct but OUTPUT not moulded properly as per the question
		 due to time issue !!!
source : 410 - station imbalance on online UVA.
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class specimen{
public: 
	int w;
	int i;
};

bool comparator1(specimen a, specimen b){
	// incresing order of weights 
	return a.w < b.w; 
}

bool comparator2(specimen a, specimen b){
	return a.i < b.i;
}

int main(){

int c;	// chambers
int s;	// specimens

cin>>c>>s;
int redundantZeros = 2*c - s;	// main logic of problem 

specimen def;
def.w = 0;
def.i = -1;

vector<specimen> v(redundantZeros, def);
// get the weights of the specimens 
float average = 0;
for(int i=0; i<s; i++){
	specimen s;
	cin>>s.w;
	s.i = i;

	average += s.w;
	v.push_back(s);
}
average/=s;	// average of all the specimens 

// view the vector 
// for(int i=0; i<v.size(); i++){
// 	cout<<v[i]<<endl;
// }

sort(v.begin(),v.end(), comparator1);	// sort the vector

int imbalance = 0;	// total imbalance for this set 

for(int i=0; i<c; i++){
	cout<<i<<": ";

	// allocate elements to the chamber 
	specimen s1 = v[i], s2 = v[2*c-1-i];
	int sum = s1.w + s2.w;
	imbalance += abs(average - sum);

	//print the chambers 
	if(s1.i<s2.i){
		if(s1.w)
			cout<<s1.w<<" ";
		if(s2.w)
			cout<<s2.w<<" ";
	}
	else{
		if(s2.w)
			cout<<s2.w<<" ";
		if(s1.w)
			cout<<s1.w<<" ";
	}
	cout<<endl;
}

return 0;
}