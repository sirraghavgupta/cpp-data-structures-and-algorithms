// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Comparator to sort the string by 
// their lengths in decreasing order 
bool compare(string s1, string s2) 
{ 
	return s1.size() > s2.size(); 
} 

// Function that returns true if string s can be 
// made up of by other two string from the array 
// after concatenating one after another 
bool canbuildword(string& s, bool isoriginalword, 
				map<string, bool>& mp) 
{ 

	// If current string has been processed before 
	if (mp.find(s) != mp.end() && mp[s] == 0) 
		return false; 

	// If current string is found in the map and 
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

		// If left sub-string is found in the map and 
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

// Function to return the longest string 
// that can made be made up from the 
// other string of the given array 
void printlongestword(vector<string> listofwords) 
{ 

	// Put all the strings in the map 
	map<string, bool> mp; 
	for (string s : listofwords) { 
		mp[s] = 1; 
	} 

	// Sort the string in decreasing 
	// order of their lengths 
	// sort(listofwords.begin(), listofwords.end(), compare); 

	// Starting from the longest string 
	int count=0;
	for (string s : listofwords) { 

		// If current string can be made 
		// up from other strings 
		if (canbuildword(s, 1, mp)){
			cout<<s<<endl;
			count++;
		} 
		if(count==2)
			return;
	}
} 

// Driver code 
int main() 
{ 

	ifstream fin;
	vector<string> listofwords;
// create the dataset in hashmap
    	

    fin.open("words1.txt");
    string key;
    while(getline(fin,key)){
      listofwords.push_back(key);
    }
    fin.close();

    sort(listofwords.begin(), listofwords.end(), compare); 
    
	// for(int i=0; i<listofwords.size(); i++){
	// 	cout<<listofwords[i]<<endl;
	// }

	printlongestword(listofwords); 

	return 0; 
} 
