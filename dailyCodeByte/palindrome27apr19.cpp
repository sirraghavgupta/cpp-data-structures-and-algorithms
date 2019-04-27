/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 april 2019
AIM    : to check whether the numbers form a palindrome or not
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

bool palindrome(int n, int arr[]){
  for(int i=0; i<n/2; i++){
    if(arr[i]!=arr[n-1-i]){
      return false;
    }
  }
  return true;
}

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++){
  cin>>arr[i];
}

palindrome(n, arr)?cout<<"True":cout<<"False";

return 0;
}
