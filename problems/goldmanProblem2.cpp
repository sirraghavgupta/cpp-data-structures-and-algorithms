/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 august 2019
AIM    : to calculate the product of rest all elements in an array, for each 
         element.
         dont use the / operator
         expected time complexity O(n)
         eg  - array = [1   2  3  4  5]
               ans   = [120 60 40 30 241]
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>

using namespace std;

vector<int> findSpecialProduct(vector<int> inputArray) {
    
        int n = inputArray.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> pro(n, 0);

        if(n==0)
            return pro;

        left[0] = inputArray[0];
                right[n-1] = inputArray[n-1];

        // build the product array from left
        // left[i] holds the product of all elements upto i
        for(int i=1; i<n; i++){
            left[i] = left[i-1] * inputArray[i];
        }

        // build the product array from right
        // right[i] holds the product of all elements upto i, - from back
        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1] * inputArray[i];
        }

        // get actual answer
        for(int i=0; i<n; i++){
            if(i==0)
                pro[i] = right[i+1];
            else if(i==(n-1))
                pro[i] = left[i-1];
            else
                pro[i] = left[i-1] * right[i+1];
        }

        return pro;


}

int main()
{
    int n;
    cin>>n;

    vector<int> v(n), r(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    // v.shrink_to_fit();

    r = findSpecialProduct(v);
    for(int i=0; i<n; i++){
        cout<<r[i]<<" ";
    }
    cout<<endl;
}
