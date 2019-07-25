/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 july 2019
AIM    : check balanced parenthesis using stack.
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
		if(ch=='(')
			s.push(ch);
		// pop an opening bracket for every closing bracket
		else if(ch==')'){
			if(s.empty() || s.top()!='(')	
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