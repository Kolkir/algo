#ifndef _SUBSET_H_

#include <cmath>
#include <vector>
#include <cstddef>

namespace algo
{
template<class I, class CB>
void subsets(I start, I end, CB callback)
{
	auto length = std::distance(start, end);
	auto count = std::pow(2, length);
	std::vector<typename I::value_type> subSet;
	
	auto getBit = [](int value, int position) -> int
	{
		int bit = value & static_cast<int>(std::pow(2, position));
		return (bit > 0 ? 1 : 0);
	};
	
	for (decltype(count) i = 0; i < count; ++i)
	{
		subSet.clear();
		for (int bitIndex = 0; bitIndex < static_cast<int>(length); ++bitIndex)
		{
			if (getBit(i, bitIndex) == 1)
			{
				auto item = start;
				std::advance(item, bitIndex);
				subSet.push_back(*item);
			}
		}
		callback(subSet);
	}
	
} 

void subsets_test();

}

#endif