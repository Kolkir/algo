#ifndef _COMBINATIONS_H_

#include <cmath>
#include <vector>
#include <cstddef>
#include <stack>
#include <algorithm>

namespace algo
{
//not order sensetive, exect length
template<class I, class CB, class B>
void combinations(I start, I end, B& buffer, size_t combLen, size_t n_chosen, I at, CB callback)
{
	if (n_chosen == combLen)
	{
		callback(buffer);
	}
	else
	{	
		auto i = at;
		auto e = end;
		for(; i != e; ++i)
		{
			buffer[n_chosen] = *i;
			combinations(start, end, buffer, combLen, n_chosen + 1, i, callback); 
		};		
	}
}

//not order sensetive, all lengths
template<class I, class CB, class B>
void combinations_all(I start, I end, B& buffer, size_t maxLen, size_t n_chosen, I at, CB callback)
{
	if (n_chosen < maxLen)
	{
		auto i = at;
		auto e = end;
		for(; i != e; ++i)
		{
			buffer[n_chosen] = *i;			
			callback(buffer.begin(), buffer.begin() + n_chosen + 1);
			combinations_all(start, end, buffer, maxLen, n_chosen + 1, i, callback); 
		};		
	}
}

//order sensetive, all lengths
template<class I, class CB, class B>
void combinations_all2(I start, I end, B& buffer, size_t maxLen, size_t n_chosen, CB callback)
{
	if (n_chosen < maxLen)
	{
		auto i = start;
		auto e = end;
		for(; i != e; ++i)
		{
			buffer[n_chosen] = *i;			
			callback(buffer.begin(), buffer.begin() + n_chosen + 1);
			combinations_all2(start, end, buffer, maxLen, n_chosen + 1, callback); 
		};		
	}
}
void combinations_test();

}

#endif