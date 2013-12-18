#include "subset.h"

#include <iostream>
#include <iterator>

namespace algo
{
namespace
{
void subsetcb(const std::vector<int>& m)
{
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}	
}
	
void subsets_test()
{
	std::vector<int> m = {1, 2, 3};
	subsetcb(m);
	std::cout << std::endl;
	
	subsets(m.begin(), m.end(), subsetcb);
}
}