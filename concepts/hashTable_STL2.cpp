/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : play with hash table STL 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

class fruit{
	public:
		string name;
		int price;
		string city;

		fruit(){
			// efault cTor is required when we make para CTor 
		}
		fruit(string n, int p, string c){
			name = n;
			price = p;
			city = c;
		}
};

int main(){

unordered_map<string, fruit> myMap;

// insert a fruiti obj 
fruit f("apple", 100, "delhi");
myMap[f.name] = f;

// how to search and acces other values of obj 
fruit fs = myMap["apple"];
cout<<fs.city<<endl;
cout<<fs.price<<endl;

// insert more 
fruit f2("mango", 300, "delhi");
myMap[f2.name] = f2;

cout<<myMap["mango"].price<<endl;


//update the values 
fruit f3("mango", 600, "delhi");
myMap[f3.name] = f3;

cout<<myMap["mango"].price<<endl;


// use count function to exist existence 
cout<<"apple : "<<myMap.count("apple")<<endl;
cout<<"mango : "<<myMap.count("mango")<<endl;

cout<<"entera fruit to search"<<endl;
string fru;
cin>>fru;

if(myMap.count(fru))
	cout<<"exists"<<endl;
else
	cout<<"not exists"<<endl;


// how to erase 
myMap.erase("mango");
cout<<"apple : "<<myMap.count("apple")<<endl;
cout<<"mango : "<<myMap.count("mango")<<endl;

return 0;

}