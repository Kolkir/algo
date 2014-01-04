#include "findstring.h"

#include <string>
#include <iostream>

namespace algo
{
void find_string_test()
{
    std::string s = "abababcbab";
       
    auto pos = s.find("ababcb");
    std::cout << pos << std::endl;
    
    pos = find_string(std::string("ababcb"), s);
    std::cout << pos << std::endl;
}
}
