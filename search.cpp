#include "search.h"

#include <vector>
#include <iostream>

namespace algo
{
void search_test()
{
	std::vector<int> m = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	auto i = algo::search(m.begin(), m.end(), 12);
	std::cout << "Look for 12 get:" << *i << std::endl;
	
	i = algo::search(m.begin(), m.end(), 45);
	if (i == m.end())
	{
		std::cout << "Look for 45 failed - ok" << std::endl;
	}
	else
	{
		std::cout << "Look for 45 success - bad" << std::endl;
	}
}
}