#ifndef _SEARCH_H_

#include <cstddef>
#include <algorithm>

namespace algo
{
	
template <class I>
I getMiddle(I start, I end)
{
	if (start != end)
	{
		auto len = std::distance(start, end);
		if (len >2)
		{
			len = len / 2;
			auto r = start;
			std::advance(r, len);
			return r;
		}
	}
	return end;
}

template <class I>
I search(I start, I end, const typename I::value_type& val)
{
	auto m = getMiddle(start, end);
	
	if (m != end)
	{
		if (val == *m)
		{
			return m;
		}
		else if (*m > val)
		{
			return search(start, m, val);
		}
		else
		{
			return search(m, end, val);
		}
	}
	return end;
}

void search_test();
}

#endif
