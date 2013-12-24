#ifndef _QSORT_H_

#include <algorithm>

namespace algo
{

template<class I>
I privotList(I start, I end)
{
	auto pivotValue = *start;
	auto pivotPos = start;
	auto i = std::next(start);
	for(;i != end; ++i)
	{
		if (*i < pivotValue)
		{
			std::advance(pivotPos, 1);
			std::swap(*pivotPos,*i);
		}
	}
	std::swap(*pivotPos,*start);
	return pivotPos;
}	

template<class I>
void qsort(I start, I end)
{
	if (start != end)
	{
		auto p = privotList(start, end);
		qsort(start, p);
		qsort(std::next(p), end);
	}
}	

void qsort_test();
}

#endif
