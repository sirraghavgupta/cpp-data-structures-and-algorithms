/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : find unique elements in an array by "searching before that element" if 
		 it had already occured or not"

STATUS : !!! success !!!
NOTE   : one approach is in hashTable_uniqueNumbersFromArray.cpp also
##############################################################################*/


#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n;
    cin>>n;
    int arr[n];
    // read the array 
    for(int i=0; i<n; i++)
        cin>>arr[i];

    // search for unique number 
    for(int i=0; i<n; i++){
        int j;
        // check if that element had already occured 
        for(j=0; j<i; j++){
            if(arr[j]==arr[i])
                break;
        }
        // if element was not found and loop ran complete. 
        if(j==i)
            cout<<arr[i]<<endl;
    }

return 0;
}
