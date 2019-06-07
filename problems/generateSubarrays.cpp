/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : to print all the subarrays of a given array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main() {

    int arr[100];
    
    int n;      // size of the array
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int count=0;
    for(int i=0; i<n; i++){       // selecting the starting index of the subarray
        for(int j=i; j<n; j++){   // ending index of subarray
            
            count++;                //count the number of subarrays
            //printing the subarray[i,j]
            for(int k=i; k<=j; k++)
                    cout<<arr[k]<<" ";
            cout<<endl;
        }
    }
cout<<"total number of subarrays generated "<<count<<endl;          //actually n(n+1)/2 
return 0;
}
