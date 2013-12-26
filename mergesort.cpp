#include "mergesort.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace algo
{
void mergesort_test()
{
	std::vector<int> m1 = {2, 4, 6, 8, 10, 56,778,99};
	std::vector<int> m2 = {1, 3, 5, 7, 9, 70};	
	
	std::vector<int> m;
	
	algo::merge(m1.begin(), m1.end(),
				m2.begin(), m2.end(),
				std::back_inserter(m));
	
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}
}