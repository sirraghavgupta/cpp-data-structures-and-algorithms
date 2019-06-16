/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 june 2019
AIM    : there are n boards, k painters
		 size of boards is given in terms of units in an array
		 time taken to paint one unit is 'time' units
		 find the minimum amount of time required to paint the boards
		 one painter can paint one board only at one time
NOTE   : this problem is exactly same as the book allocation problem
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#define ll long long int
using namespace std;

//  ------------------------------------------------------------------
bool checkPossibility(int size[], int n, ll target, int m){
	// check the possibility that no painter will paint area more than target
	// this is done by counting the number of painters required to print all boards 
	// keeping in mind the limit of area for a painter

	int painterCount=1;	// initially take one painter only
	ll curr_area=0;	// current pages alloted to a painter 
	int i=0;		 	// iterator to traverse all boards

	while(i<n){		// to traverse all boards
		
		if(curr_area+size[i]>target){		// if i can't alot one more board to the painter
			curr_area=0;				// reset the current area alloted
			painterCount++;				// take one more painter
			if(painterCount>m)		return false; // if number of painters required are more than that 
						// specified in the problem, then possibility fails
		}	
		else{			// one more board can be alloted to the painter
			curr_area+=size[i];		// alot the board
			i++;					// move to the next board now
		}
	}
	return true;
}

// -------------------------------------------------------------------------

ll binSearchboards(int size[], int n, int m, int totalArea){
	ll mid;		
	int start=0;
	ll end=totalArea;
	ll ans=totalArea;
	while(start<=end){

		mid = (start+end)/2;
 
		if(checkPossibility(size,n,mid,m)){
			/* if there is a possibility that m painters can paint these boards with 
			   no painter painting more than 'mid' area, then check for optimal
			   solution by going towards the left of mid. */
			end=mid-1;
			ans=mid;		// keep this as the current answer
		}
		else{
			start=mid+1;    // if possiblity fails, then try to take a bigger limit of pages
		}
	}
	return ans;
}

int main(){

int n,m,time;		// n - number of boards, m - number of painters
cin>>n>>m>>time;	// time - time taken to paint one unit of area of board
	
int size[n];		// stores the area in units of a board
ll totalArea=0;		// total area of all the boards- denote the max area for a painter 
					// in worst case - if there is single painter - refers to max time

for(int i=0; i<n;i++){		// read the size values 
	cin>>size[i];
	totalArea+=size[i];
}

ll answer = time*binSearchboards(size, n, m, totalArea); 
cout<<answer%10000003<<endl;

return 0;
}