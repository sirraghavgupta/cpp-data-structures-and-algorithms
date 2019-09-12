/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 september 2019
AIM    : check balanced parenthesis using stack
		 all kinds of brackets are there in the string
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <stack>
using namespace std;

bool balancedParenthesis(string expr){

	stack<char> s;	// templated already 

	for(int i=0; i<expr.length(); i++){
		char ch = expr[i];
		
		// push all opening brackets
		if(ch=='(' || ch=='{' || ch=='[')
			s.push(ch);

		// pop an opening bracket for every corresponding closing bracket
		else if(!s.empty()){
			if(ch==')' && s.top()!='(')	
				return false;

			else if(ch=='}' && s.top()!='{')	
				return false;
		
			else if(ch==']' && s.top()!='[')	
				return false;

			s.pop();
		}
		
	}
return s.empty();
}

int main(){

string expr;
cin>>expr;

balancedParenthesis(expr)?cout<<"valid"<<endl:cout<<"invalid"<<endl;

return 0;
}