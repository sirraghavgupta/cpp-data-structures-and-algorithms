/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 24 august 2019
AIM    : to find out 2 longest strings in the file which can be made by using
		 other smaller strings in the file
STATUS : !!! success !!!
##############################################################################*/


#include <bits/stdc++.h> 
using namespace std; 


bool comparator(string s1, string s2) 
	{	 
		// sort the strings in decreasing order of length 
		// same length strings lexicographically
		if(s1.length() == s2.length())
			return s1<s2;
		return s1.length() > s2.length(); 
	} 


bool checkCombinations(string& s, bool isMainString, unordered_map<string, bool>& statusMap) 
{ 
	// returns true if the string is possible to be made by using other strings
    
	// If the string exists in map but was already processed and found to be a failure
	if (statusMap.find(s) != statusMap.end() && statusMap[s] == 0) 
		return false; 

    // if the string exists and is a success AND is not the original word itself
	if (statusMap.find(s) != statusMap.end() && statusMap[s] == 1 && isMainString == 0) { 
		return true; 
	} 

    // unprocesses string or substring 
	for (int i = 1; i < s.length(); i++) { 

        // divide the string into 2, from left, in all possible combinations and if the left part is a success, then check for right part also.
        // left + right = string itself
		string left = s.substr(0, i); 
		string right = s.substr(i); 

        // if left part is success, check for right part also
		if (statusMap.find(left) != statusMap.end() && statusMap[left] == 1 && checkCombinations(right, 0, statusMap))
			return true;
	} 

	// no combination was found in which the string could be constructed
    // add it as a failure for future reference and return false
	statusMap[s] = 0; 
	return false; 
} 


int main() 
{ 
	// -------------------
	 clock_t start, end;
	 start=clock();
	// -------------------

	vector<string> v;
	string filename;
	cin>>filename;

	// read the data into a vector for sorting and easy access
	ifstream fin;
    fin.open(filename);
    string key;
    while(getline(fin, key)){
      v.push_back(key);
    }
    fin.close();

    // sort in decreasing order of length
    sort(v.begin(), v.end(), comparator); 
    
	/*	
		// check if the data was gathered correctly
		for(int i=0; i<100; i++)
			cout<<v[i]<<endl;
	*/

	
	// now do the searching task

	// Put all the strings in the unordered_map for fast direct access 
	unordered_map<string, bool> statusMap; 
	for(int i=0; i<v.size(); i++){ 
		statusMap[v[i]] = 1; 
	}  

	// process the strings in decreasing order of length
	int count=0;
	
	for (int i=0; i<v.size(); i++){ 
	// string s = v[i];
	if (checkCombinations(v[i], 1, statusMap)){
		cout<<v[i]<<endl;
		count++;
	} 
	if(count==2)
		break;
	}

	// ----------------------------- clocking part ---------------------------
	end=clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout<<fixed<<time_taken<<endl;
	cout<<"sec";

	return 0; 
} 
