#include "factorial.h"

namespace algo
{
int factorial_rec(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial_rec(n - 1);		
	}
}

int factorial_ser(int n)
{
	int res = 1;
	for(int i = 2; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}
}