/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 july 2019
AIM    : to learn how to use random function to shuffle an array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffleArray(int arr[], int s, int e){

	srand(time(NULL));

	for(int i=e; i>0; i--){
		int index = rand()%(i+1);
		swap(arr[index], arr[i]);
	}
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

shuffleArray(arr, 0, n-1);

for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}