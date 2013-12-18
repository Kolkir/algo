#include "permutation.h"

#include <iostream>
#include <vector>

namespace algo
{
	
void permcb(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::copy(start, end, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void permutation_test()
{
	std::vector<int> m = { 1, 2, 3};
	permutations(m.begin(), m.end(), m.begin(), permcb);

	std::cout << std::endl;
	
	m = {1, 2, 3};
	permcb(m.begin(), m.end());
	while (algo::next_permutation(m.begin(), m.end()))
	{
		permcb(m.begin(), m.end());
	}	
}	
}