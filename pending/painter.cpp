/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 May 2019
AIM    : to find out the minimum time required to paint n number of boards by 
		 k painters.
		 each board can be painted by a single painter. 
		 the number of boards is given and their sizes also as they can be of 
		 different sizes.
		 a board of size s will take s units of time.

NOTE   : basically, any painter can pick any board and paint that. moto is to finish 
	 	 the work as soon as possible

	====== MODIFCATION OF DAILY CODE BYTE OF 27 MAY 2019 =====

STATUS : !!! ----- !!!
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

void readArray(int arr[], int size){		// read an array
	for(int i=0; i<size; i++){
		cin>>arr[i];
	}
}
void dumpArray(int arr[], int size){	 	// print an array
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}
int minArray(int arr[], int size){			// find index of min value in array
	int minI=0;
	for(int i=1; i<size; i++){
		minI=(arr[i]<arr[minI])?i:minI;
	}
	return minI;
}
int maxArray(int arr[], int size){
	int maxI=0;
	for(int i=1; i<size; i++){
		maxI=(arr[i]>arr[maxI])?i:maxI;
	}
	return maxI;
}

bool comparator(int a, int b){
	return a>b;
}
//-----------------------------------------

int main(){

int totPainters;
int totBoards;
int minTime=0;
cin>>totPainters>>totBoards;

int job[totPainters];
int boards[totBoards];
readArray(boards, totBoards);
sort(boards, boards+totBoards, comparator);
dumpArray(boards, totBoards);
// cout<<minArray(boards, totBoards);

for(int i=0; i<totPainters; i++){
	job[i]=boards[i];
}
cout<<"after copying "<<endl;
dumpArray(job, totPainters);

int jobPointer=totPainters;
cout<<"inside loop "<<endl;

while(jobPointer<totBoards){
	int minIndex = minArray(job, totPainters);
	cout<<"minIndex = "<<minIndex<<endl;
	int minValue = job[minIndex];
	cout<<"minValue = "<<minValue<<endl;
	for(int i=0; i<totPainters; i++){
		job[i]-=minValue;
	}
	dumpArray(job, totPainters);	
	minTime+=minValue;
	cout<<"minTime = "<<minTime<<endl;
	job[minIndex]=boards[jobPointer];
	dumpArray(job, totPainters);
	jobPointer++;
	cout<<"jobPointer = "<<jobPointer<<endl;
	cout<<"----------"<<endl;	
}
cout<<"end loop"<<endl;
cout<<"----------------------"<<endl;
cout<<maxArray(boards, totBoards)<<endl;
minTime+=job[maxArray(job, totPainters)];
cout<<"minTime = "<<minTime<<endl;
return 0;
}