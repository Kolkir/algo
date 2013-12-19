#include "combinations.h"

#include <iostream>
#include <iterator>

namespace algo
{
namespace
{
void combcb(const std::vector<int>& m)
{
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}	

void combcb_all(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}	
}
	
void combinations_test()
{
	std::vector<int> m = {1, 2, 3};
	
	size_t combLen = 3;
	std::vector<int> buffer(combLen);
	
	combinations(m.begin(), m.end(), buffer, combLen, 0, m.begin(), combcb);
	
	std::cout << std::endl;
	
	combinations_all(m.begin(), m.end(), buffer, combLen, 0, m.begin(), combcb_all);
	
	std::cout << std::endl;
	
	combinations_all2(m.begin(), m.end(), buffer, combLen, 0, combcb_all);
}
}