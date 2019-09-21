/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to implement hash table for string keys.
STATUS : !!! success !!! -- awesome !!!
NOTE   : very important code
##############################################################################*/

#include <iostream>
#include "hashtable.h"
using namespace std;

int main(){

hashtable<int> h(11);	// key of string type by default

h.insert("mango", 100);
h.insert("apple", 200);
h.insert("banana", 300);
h.insert("guava", 400);
h.insert("pineapple", 500);
h.insert("kiwi", 20);
h.insert("orange", 40);
h.insert("lemon", 25);
h.insert("pmegranate", 600);

h.print();

cout<<"searched values"<<endl;
cout<<*h.search("orange")<<endl;
cout<<*h.search("mango")<<endl;

h["potato"] = 1000;
h["tomato"] = 5000;
h.print();

cout<<h["mango"]<<endl;
cout<<h["kiwi"]<<endl;

h["mango"] = 9000;
h.print();

return 0;
}