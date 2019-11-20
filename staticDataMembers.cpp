/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 september 2019
AIM    : 
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

class Something
{
public:
    static int s_value;	// just kind of forward declaration that a static var exists
};
 
int Something::s_value;	// compulsory to write this line = definition

int main()
{
    // note: we're not instantiating any objects of type Something
 	// static members can be accessed directly from the class name
    // Something::s_value = 2;
    std::cout << Something::s_value++ << '\n';
    std::cout << Something::s_value<< '\n';
    // static member exists without the creation of an object also.	
    return 0;
}

// int main()
// {
//     Something first;
//     Something second;
 
//     first.s_value = 2;
 
//     std::cout << first.s_value << '\n';
//     std::cout << second.s_value << '\n';
//     return 0;
// }