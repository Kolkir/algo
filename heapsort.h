#ifndef _HEAPSORT_H_

#include <algorithm>

namespace algo
{	
	
template<class I, class D>
void shiftRight(D rootIdx, D lastIdx, I start)
{
	while (rootIdx * 2 + 1 <= lastIdx)
	{
		auto leftChildIdx = rootIdx * 2 + 1;		
		auto rightChildIdx  = leftChildIdx + 1;
		
		auto leftChild = start;
		std::advance(leftChild, leftChildIdx);
		
		auto rightChild = start;
		std::advance(rightChild, rightChildIdx);
		
		auto root = start;
		std::advance(root, rootIdx);
		
		auto swapChild = root;
		auto swapIdx = rootIdx;
		
		if (*swapChild < *leftChild)
		{
			swapChild = leftChild;
			swapIdx = leftChildIdx;
		}
		
		if (rightChildIdx <= lastIdx && 
			*swapChild < *rightChild)
		{
			swapChild = rightChild;
			swapIdx = rightChildIdx;
		}
		
		if (swapChild != root)
		{
			std::swap(*root, *swapChild);
			rootIdx = swapIdx;
		}
		else
		{
			break;
		}		
	}
}	

template<class I>
typename I::difference_type heapify(I start, I end)
{
	auto lastIdx = std::distance(start, end) - 1;	
	auto midIdx = (lastIdx - 1) / 2;	
	
    for (decltype(midIdx) i = 0, j = midIdx; i <= midIdx; ++i, --j)
    {
        shiftRight(j, lastIdx, start);		
    }
    return lastIdx;	
}
	
template<class I>
void heapsort(I start, I end)
{
	auto lastIdx = heapify(start, end);
	
	for (decltype(lastIdx) i = 0, j = lastIdx; i < lastIdx; ++i)
    {
		auto last = start;
		std::advance(last, j);
		std::swap(*start, *last);
		--j;
		shiftRight(0, j, start);
	}	
}	

void heapsort_test();
}

#endif
