/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : to find the subarray with the maximum sum and print the sum also 
STATUS : !!! success !!!
TIME   : O(n^3) --very bad
##############################################################################*/

#include <iostream>
using namespace std;
int main(){
    int n;      // size of the array
    cin>>n;

    int arr[100];       
    for(int i=0; i<n; i++)      // read the array
        cin>>arr[i];

    int mxSum=-25648556, mxi, mxj;      // attributes of the maximum subarray
    int newsum;           // sum of a subarray under consideration in one time

    for(int i=0; i<n; i++){         //selecting the starting index of the subarray
        for(int j=i; j<n; j++){     //ending index of subarray

            newsum=0;

            //printing the subarray[i,j]
            for(int k=i; k<=j; k++)
                  newsum+=arr[k];    //sum of current subarray

            if(newsum>mxSum){
                mxSum=newsum;
                mxi=i;
                mxj=j;
            }
        }
    }
cout<<"the sum of max subarray is:  "<<mxSum<<endl;          //actually n(n+1)/2 
cout<<"maximum subarray is: "<<endl;
for(int k=mxi; k<=mxj; k++)
        cout<<arr[k]<<", ";
cout<<endl;
return 0;
}

