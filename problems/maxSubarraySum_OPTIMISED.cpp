/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : to find the subarray with the maximum sum and print the sum also 
STATUS : !!! success !!!    
time complexity : O(n^2)
##############################################################################*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[n];
    int cummSum[n];     // to store the cumulative sum of the array

    cin>>arr[0];
    cummSum[0]=arr[0]; 
    for(int i=1; i<n; i++){     // prepare the array and cummulative sum array 
        cin>>arr[i];
        cummSum[i]=cummSum[i-1] + arr[i];
    }

    int mxSum=-23561546, mxi=0, mxj=0;  // attributes of the maximum subarray
    int currsum;

    // now we will process all the possible sub arrays
    for(int i=0; i<n; i++){         //selecting the starting index of the subarray
        for(int j=i; j<n; j++){     //ending index of subarray

            currsum = cummSum[j] - cummSum[i-1];     //finding the sum of current subarray

            //checking for maximum sum
            if(currsum>mxSum){
                mxSum=currsum;
                mxi=i;
                mxj=j;
            }
        }
    }
cout<<"the sum of max subarray is:  "<<mxSum<<endl;          //actually n(n+1)/2 
cout<<"maximum subarray is: "<<endl;
for(int k=mxi; k<=mxj; k++)
        cout<<arr[k]<<", ";
return 0;
}

