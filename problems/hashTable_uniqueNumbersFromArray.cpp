/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to find out the unique numbers from an arrays
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    unordered_map<int, bool> unique;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        unique[arr[i]] = 1;
    }

    for (auto x : unique) 
      cout << x.first << endl; 

return 0;
}