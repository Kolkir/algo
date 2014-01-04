#ifndef _NUMERIC_H_

#include <algorithm>
#include <iterator>

namespace algo
{

template<class I>   
double polynomial(double x, I astart, I aend)
{
   if (astart != aend)
   {
        double result = *astart + x * (*std::next(astart));
        double xPower = x;
        ++astart;
        ++astart;
        for(; astart != aend; ++astart)
        {
            xPower *= x;
            result += *astart * xPower;
        }
        return result;
   } 
   return 0.0;
}
    
template<class I>   
double horners_polynomial(double x, I astart, I aend)
{
   if (astart != aend)
   {
        std::reverse_iterator<I> rbegin(aend);
        std::reverse_iterator<I> rend(astart);
        double result = *rbegin;
        ++rbegin;
        for(; rbegin != rend; ++rbegin)
        {
            result *= x;
            result += *rbegin;
        }
        return result;
   } 
   return 0.0;
}

void numeric_test();

}

#endif
