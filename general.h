#include <iostream>
using namespace std;


void bubble_sort(int arr[], int n){
  // sort an array of size n in ascending order
  for(int i=0; i<n-1; i++){
     for(int j=i+1; j<n; j++){
      int temp;
      if(arr[i]>arr[j]){
        temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }
  } 
}

int getLength(int number){
  // find the number of digits in a number
  int length=0;
  while(number>0){
  number/=10;
  length++;
  }
return length;
}

int splitNumber(int number, int digits[], int length){
  // prepares a digit array of a number in " -- reverse order -- "
  int count=0;
  while(number>0){
    digits[count]=number%10;
    number/=10;
    count++;
  }
}

void printArray(int arr[], int n){
  // read an array of size n
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void readArray(int arr[], int n){
  // print an array of size n
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
}

bool compArrays(int arr1[], int arr2[], int n){ 
  // to check whether 2 arrays are equal or not
  for(int i=0; i<n; i++){
    if(arr1[i]!=arr2[i])
      return false;
  }
  return true;
}