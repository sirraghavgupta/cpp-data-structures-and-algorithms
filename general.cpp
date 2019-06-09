#include <iostream>
using namespace std;


void bubble_sort(int arr[], int n){
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
  int length=0;
  while(number>0){
  number/=10;
  length++;
  }
return length;
}

int splitNumber(int number, int digits[], int length){
  int count=0;
  while(number>0){
    digits[count]=number%10;
    number/=10;
    count++;
  }
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void readArray(int arr[], int n){
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
}