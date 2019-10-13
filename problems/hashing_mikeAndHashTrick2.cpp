
/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 september 2019
AIM    : Mike loves hashing. He decides to create his own hashing technique, so 
         he creates a Hash Function, given as 
STATUS : !!! success !!!
NOTE   : this is the final optimised approach discussed bu bhaiya in the video.
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.second<b.second;
}

int main(){

int n;
cin>>n;

vector<pair<int, int>> v;
unordered_map<int, int> mp;

// read the array input 
int arr[n];
for(int i=0; i<n; i++){
	cin>>arr[i];
	mp[arr[i]] = i;
}

// transfer map to the vector
for(auto it:mp){
	v.push_back(it);
}

// sprt the map according to the second value.
sort(v.begin(), v.end(), comparator);

// print the map
for(int i=0; i<v.size(); i++){
    cout<<v[i].first<<endl;
    // cout<<v[i].first<<" -> "<<v[i].second<<endl;
}

return 0; 
}