/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 24 august 2019
AIM    : to find out 2 longest strings in the file which can be made by using
		 other smaller strings in the file
STATUS : !!!  !!!
##############################################################################*/


#include <bits/stdc++.h> 
using namespace std; 


bool comparator(string s1, string s2) 
	{	 
		// sort the strings in decreasing order of length
		return s1.size() > s2.size(); 
	} 


bool canbuildword(string& s, bool isoriginalword, unordered_map<string, bool>& mp) 
{ 
	// returns true if the string is possible to be made by using other strings

	// If current string has been processed before 
	if (mp.find(s) != mp.end() && mp[s] == 0) 
		return false; 

	// If current string is found in the unordered_map and 
	// it is not the string under consideration 
	if (mp.find(s) != mp.end() && mp[s] == 1 
		&& isoriginalword == 0) { 
		return true; 
	} 

	for (int i = 1; i < s.length(); i++) { 

		// Split the string into two 
		// contiguous sub-strings 
		string left = s.substr(0, i); 
		string right = s.substr(i); 

		// If left sub-string is found in the unordered_map and 
		// the right sub-string can be made from 
		// the strings from the given array 
		if (mp.find(left) != mp.end() && mp[left] == 1 
			&& canbuildword(right, 0, mp)) { 
			return true; 
		} 
	} 

	// If everything failed, we return false 
	mp[s] = 0; 
	return false; 
} 


void findStrings(vector<string> &v) 
{ 
	// find the 2 longest desirable strings in the vector 

	// Put all the strings in the unordered_map 
	unordered_map<string, bool> mp; 
	for (string s : v) { 
		mp[s] = 1; 
	}  

	// process the strings in decreasing order of length
	int count=0;
	for (string s : v){ 

	
		if (canbuildword(s, 1, mp)){
			cout<<s<<endl;
			count++;
		} 
		if(count==2)
			break;
	}
	return;
} 

// Driver code 
int main() 
{ 

	// -------------------
	 clock_t start, end;
	 start=clock();
	// -------------------

	vector<string> v;

	// read the data into a vector for sorting and easy access
	ifstream fin;
    fin.open("words1.txt");
    string key;
    while(getline(fin,key)){
      v.push_back(key);
    }
    fin.close();

    // sort 
    sort(v.begin(), v.end(), comparator); 
    
	/*	
		// check if the data was gathered correctly
		for(int i=0; i<100; i++)
			cout<<v[i]<<endl;
	*/

	findStrings(v); 

	// ----------------------------- clocking part ---------------------------
	end=clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout<<fixed<<time_taken<<endl;
	cout<<"sec";

	return 0; 
} 
