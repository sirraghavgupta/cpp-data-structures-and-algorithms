/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : find unique numbers in an array using sorting approach 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    // read the array 
    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr, arr+n);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for(int i=0; i<n; i++){
        if(arr[i]!=arr[i-1] || i==0)
            cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}