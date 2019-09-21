#include <iostream>
#include <cstring>
using namespace std;


bool isPrime(int n){
  if(n==1)
    return false;

  if(n==2)
    return true;

  if(n%2==0)
    return false;

  for(int i=3; i<n; i+=2){
    if(n%i == 0)
      return false;
  }
  return true;
}

template<typename t>
class node{
public:
	string key;
	t value;
	node<t> *next;

	node(string key, t value){
		this->key = key;
		this->value = value;
		next = NULL;
	}

	~node(){
		// destructor chaining
		// it will first destroy the object linked to it and then itself
		// and this happens recursively
		// so i call delete head; only ----:) :)
		// superb -------------------------------
		if(next)
			delete next;
	}
};

template<typename t>
class hashtable{

private:
	node<t> **buckets;
	int cs;	// current size
	int ts;	// table size
	int prime;	// for the hash function, if u wanna change, u can 

	void rehash(){

		// get the initial table into another var and modify the original
		node<t> **oldBuckets = buckets;
		int oldTs = ts;

		ts*=2;	// double the size of new table
		// go to the next nearest prime number 
		for(int i=ts; ; i++){
			if(isPrime(i)){
				ts = i;
				break;
			}
		}

		cs=0;	// new table size = 0
		buckets = new node<t>* [ts];

		for(int i=0; i<ts; i++){
			buckets[i] = NULL;
		}

		// read from old table and insert into new
		for(int i=0; i<oldTs; i++){
			node<t>* temp = oldBuckets[i];

			if(temp){
				while(temp!=NULL){
				insert(temp->key, temp->value);
				temp = temp->next;
				// cs++; dont do this, it will be done by insert function 
				}
				//delete the old table buckets i linked list by dTor chaining 
				delete oldBuckets[i];
			}
		}
		delete [] oldBuckets;	// delete old table completely 
	}


	int hash(string key){
		int power = 1;	// power 0
		int ans = 0;
		int L =  key.length();
		for(int i=0; i<L; i++){
		//  start from end of key
			ans += key[L-i-1]*power;
			power*=prime;
			ans %= ts;
			power %= ts;
		}	
		return ans;
	}

public: 

	hashtable(int prime=37, int ts=7){
		// dont change the value of prime normally 
		this->prime = prime;
		this->ts = ts;
		cs=0;
		buckets = new node<t>*[ts];

		// initialse the buckets to be NULL.
		for(int i=0; i<ts; i++){
			buckets[i] = NULL;
		}
	}

	void insert(string key, t value){
		int index = hash(key);
		node<t>* n = new node<t>(key, value);

		n->next = buckets[index];
		buckets[index] = n;
		cs++;
		// check for too much collisions - reduction mechanism 
		float loadFactor = (float)cs/ts;

		if(loadFactor>0.7){	
			cout<<"initial list"<<endl;
			print();	// list before rehashing 
			cout<<endl;
			cout<<"load factor exceeded = "<<loadFactor<<endl;
			rehash();
		}
		return;
	}

	/*void erase(string key){
		int i = hash(key);
		node<t>* temp = buckets[i];
		node<t>* prev = temp;
		if(temp){
			// if key exists 
			if(temp->key==key){
				// if key found at head;
				buckets[i] = temp->next;

				delete temp;
				cout<<"value deleted"<<endl;
				return;
			}
		while(temp!=NULL){
			if(temp->key==key){
				prev->next = temp->next;
				delete temp;
				break;
			}
			prev = temp; 
			temp = temp->next; 
		}
	}
		cout<<"value deleted"<<endl;
		return;
	}*/

	t* search(string key){
		int i = hash(key);

		node<t>* temp = buckets[i];
		while(temp!=NULL){
			if(temp->key == key)
				return &(temp->value);	// *** 
			temp=temp->next;
		}
		return NULL;
	}

	void print(){
		for(int i=0; i<ts; i++){
			node<t>* temp = buckets[i];
			cout<<"buckets "<<i<<" - ";
		
			while(temp!=NULL){
				cout<<temp->key<<" -> "<<temp->value<<" , ";
				temp=temp->next;
				}
				
			cout<<endl;

		}
	}

	t& operator[](string key){
		t* temp = search(key);
		if(temp)
			// if key exists, return its value
			return *temp;
		else{
			// key not found, then insert the key
			t garbage;
			insert(key, garbage);
			temp = search(key);
			return *temp;
		}
		// it greatly shows what actually is reference.
		// we are not returning a pointer, but the value BY REFERENCE
		// and thus we are able to update the value in the main ..
		// superb ------------------------------------------------ 
	}

};