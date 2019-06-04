/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 june 2019 - solved earlier, but uploaded today
AIM    : find the maximum value out of an array.
STATUS : !!! success !!!
##############################################################################*/
#include<iostream>
using namespace std;

int max(int arr[], int N){		// return the max value of array
    int max=arr[0];
    for(int i=1; i<N; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

int main() {
    int N;
    cin>>N;

    int arr[N];			
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cout<<max(arr, N)<<endl;
	return 0;
}