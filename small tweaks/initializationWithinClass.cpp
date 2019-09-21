/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : try initialization of variales in c++
STATUS : !!! success !!!
##############################################################################*/

#include<iostream>
class Something
{
public:
    int m_value = 1;	// we can do this in c++ 11 
};
 
int main()

{
    Something first;
    Something second;
    
    first.m_value = 2;
 
    std::cout << first.m_value << '\n';
    std::cout << second.m_value << '\n';
 
    return 0;
}