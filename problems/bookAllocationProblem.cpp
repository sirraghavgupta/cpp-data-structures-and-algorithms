/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 june 2019
AIM    : see the image, or in the CB notes copy 1
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#define ll long long int
using namespace std;

//  ------------------------------------------------------------------
bool checkPossibility(int p[], int n, ll target, int m){
	// check the possibility that no student will read pages more than target
	// this is done by counting the number of students required to allocate all books 
	// keeping in mind the limit of pages for a student

	int studCount=1;	// initially take one student only
	ll curr_pages=0;	// current pages alloted to a student 
	int i=0;		 	// iterator to traverse all books

	while(i<n){		// to traverse all books
		
		if(curr_pages+p[i]>target){		// if i can't alot one more book to the student
			curr_pages=0;				// reset the current pages
			studCount++;				// take one more student
			if(studCount>m)		return false; // if number of studs required are more than that 
						// specified in the problem, then possibility fails
		}	
		else{			// one more book can be alloted to the student
			curr_pages+=p[i];		// alot 	the book
			i++;					// move to the next book now
		}
	}
	return true;
}

// -------------------------------------------------------------------------

ll binSearchBooks(int p[], int n, int m,ll totalPages){
	ll mid;		
	ll start=p[0];
	ll end=totalPages;
	ll ans=-1;
	while(start<=end){

		mid = (start+end)/2;
 
		if(checkPossibility(p,n,mid,m)){
			/* if there is a possibility that m students can read these books with 
			   no student reading more than 'mid' pages, then check for optimal
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

int n,m;		// n - number of books, m - number of students
cin>>n>>m;
	
int p[n];		// stores the number of pages in each book
ll totalPages=0;	// sum of pages of all books - denote the max pages for a stud 
					// in worst case - if there is single student

for(int i=0; i<n;i++){		// read the pages values 
	cin>>p[i];
	totalPages+=p[i];
}

cout<<binSearchBooks(p, n, m, totalPages)<<endl;

return 0;
}