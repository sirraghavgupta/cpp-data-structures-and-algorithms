/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 october 2019
AIM    : BIASED STANDINGS ON SPOJ
		 there are n number of teams which have their preffered ranks
		 they can have same preffered ranks
		 we have to rank them. but, everybody cant get the desired rank
		 prepare a rank list in such a way to get minimum total badness
		 BADNESS = abs(preffered rank - allocated rank)
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class team{
public:
	string name;
	int prefRank;
	// int actualRank;

	void getData(){
		cin>>name;
		cin>>prefRank;
	}
};

bool compare(team a, team b){
	return a.prefRank < b.prefRank;
}

int main(){

int t;
cin>>t;

while(t--){
int n;	// number of teams
cin>>n;

team a[n];

// for counting sort 
int freq[n+1] = {0};
freq[0] = -1;

for(int i=0; i<n; i++){
	a[i].getData();
	freq[a[i].prefRank]++;	// build the freq array simultaneously
}

// sort the teams in increasing order of preffered ranks 
// sort(a, a+n, compare);	// gives O(NlogN) complexity.


//use counting sort for O(n)
// freq array already built

// view the freq array 
// for(int i=0; i<n; i++)
// 	cout<<freq[i]<<" ";
// cout<<endl;

// now do the processing
long long int badness = 0;
int pos = 1;
for(int i=1; i<=n; i++){
	// i am only calculating badness, not allocating ranks. okay!!
	while(freq[i]!=0){
		badness += abs(pos-i);
		freq[i]--;
		pos++;
	}
}

cout<<badness<<endl;
}

return 0;
}