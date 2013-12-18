#ifndef _PERMUTATION_H_

#include <iterator>
#include <algorithm>

namespace algo
{
template <class I, class CB>
void permutations(I start, I end, I curr, CB callback)
{
	if (curr == end)
	{
		callback(start, end);
	}
	else
	{
		auto i = curr;
		for (;i != end; ++i)
		{
			std::swap(*curr, *i);
			permutations(start, end, std::next(curr), callback);
			std::swap(*curr, *i);
		}
	}
}

template <class I>
bool next_permutation(I start, I end)
{
	auto i = start;
	auto k = i;
	bool found = false;
	while (i != end)
    {
		if (std::next(i) != end &&
			*i < *std::next(i))
		{
			k = i;
			found = true;
		}
		++i;
	}
	if (found)
	{
		auto i = k;
		auto l = i;
		found = false;
		while(i != end)
		{
			if (*k < *i)
			{
				l = i;
				found = true;
			}
			++i;
		}
		if (found)
		{
			std::swap(*k, *l);
			std::reverse(std::next(k), end);
			return true;
		}
	}
	return false;
}

void permutation_test();

}

#endif