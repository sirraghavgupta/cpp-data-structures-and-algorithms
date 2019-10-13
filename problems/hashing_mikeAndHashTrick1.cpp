/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 september 2019
AIM    : Mike loves hashing. He decides to create his own hashing technique, so 
         he creates a Hash Function, given as 
STATUS : !!! DEMO success !!!
NOTE   : this is the demonstration of the actual hash function developed by mike
         as given in the problem. 
         this is not the solution
         the final optimised solition is in another file. 
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

bool comparator(int a, int b){
    return mp[a]<mp[b];
}

int main(){

int n;
cin>>n;

int arr[n];
vector<int> v;

int val;
int count = 0;
for(int i=0; i<n; i++){
    cin>>val;
    arr[i] = val;

    if(mp.count(val)){
        for(int j=0; j<i; j++){
            if(mp[arr[j]] > mp[val])
                mp[arr[j]]--;
        }
        mp[val] = count-1;
    }
    else{
        mp[val] = count;
        count++;
        v.push_back(val);
    }
}

sort(v.begin(), v.end(), comparator);

for(int i=0; i<v.size(); i++){
    cout<<v[i]<<endl;
}

return 0; 
}