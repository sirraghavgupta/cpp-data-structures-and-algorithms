/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 september 2019
AIM    : to count the frequency of all unique numbers in array of size n
		 which can have eleents only from 1-n
STATUS : !!! success !!!
TIME   : O(n)
SPACE  : O(1)
APPROACH : The idea is to traverse the given array, use elements as index and 
		 store their counts at the index. For example, when we see element 7, 
		 we go to index 6 and store the count. There are few problems to handle, 
		 one is the counts can get mixed with the elements, this is handled by 
		 storing the counts as negative. Other problem is loosing the element 
		 which is replaced by count, this is handled by first storing the 
		 element to be replaced at current index.
##############################################################################*/

#include <iostream>
using namespace std;

void countFrequency(int arr[], int n){
	// implementation 1 --- little bit complex
	for(int i=0; i<n;){
		int num = arr[i];
		if(num<=0){
			i++;
			// continue;
		}

		else{
			if(arr[num-1]>=0){
				arr[i] = arr[num-1];
				arr[num-1] = 0;
			}
			else
				arr[i]=0;
			arr[num-1]--;
		}
	}

	// to print
	for(int i=0; i<n; i++)
		cout<<i+1<<" => "<<-arr[i]<<" "<<endl;
	cout<<endl;
}

void countFrequency2(int arr[], int n){	// same idea - little bit simple
	 // Subtract 1 from every element so that the elements 
    // become in range from 0 to n-1 
    for (int j =0; j<n; j++) 
        arr[j] = arr[j]-1; 
  
    // Use every element arr[i] as index and add 'n' to 
    // element present at arr[i]%n to keep track of count of 
    // occurrences of arr[i] 
    for (int i=0; i<n; i++) 
        arr[arr[i]%n] = arr[arr[i]%n] + n; 
  
    // To print counts, simply print the number of times n 
    // was added at index corresponding to every element 
    for (int i =0; i<n; i++) 
        cout << i + 1 << " ->  " << arr[i]/n << endl; 
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

// countFrequency(arr, n);
countFrequency2(arr, n);

return 0;	
}