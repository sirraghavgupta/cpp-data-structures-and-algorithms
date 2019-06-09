/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : june 2019
AIM    : sort game problem on hackerblocks - see picture
STATUS : !!!success !!!
##############################################################################*/

#include <iostream>
#include <algorithm>
using namespace std;

bool myCompare(pair<string,int> p1, pair<string,int> p2){
	// sort in decreasing order of salary
	// if salary is same, then lexicographically
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second>p2.second;
}


int main(){

int n, minSalary;
cin>>minSalary;		// minSalary employee to be printed
cin>>n;		// number of employees

pair<string,int> emp[100005];	// to store the employee data
// read the employee data
string name;
int sal;
for(int i=0; i<n; i++){
	cin>>name;
	cin>>sal;
	emp[i].first=name;
	emp[i].second=sal;
}

sort(emp, emp+n, myCompare);

for(int i=0; i<n; i++){			// printing the required data
	if(emp[i].second>=minSalary){
		cout<<emp[i].first<<" ";
		cout<<emp[i].second<<endl;
	}
}


return 0;
}