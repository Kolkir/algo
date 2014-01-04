#include "numeric.h"

#include <iostream>
#include <vector>

namespace algo
{
void numeric_test()
{
    std::vector<double> m = {5.6, 7.8, 3.4};	

    std::cout << polynomial(1.2, m.begin(), m.end()) << std::endl;
    
    std::cout << horners_polynomial(1.2, m.begin(), m.end()) << std::endl;

	std::cout << std::endl;    
}    
}