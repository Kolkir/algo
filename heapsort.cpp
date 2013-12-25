#include "heapsort.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace algo
{
void heapsort_test()
{
	std::vector<int> m = {16, 7, 10, 1,5,11,3,8,14,4,2,12,6,13,19,15};	
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	algo::heapsort(m.begin(), m.end());
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
}