#ifndef _MERGESORT_H_

#include <algorithm>

namespace algo
{

template<class I, class OI>
void merge(I start1, I end1, 
           I start2, I end2,
           OI out)
{
    bool done = false;
    while (!done)
    {
        if (start1 != end1 && start2 != end2)
        {
            while(*start1 < *start2 &&
                   start1 != end1)
            {
                *out = *start1;
                ++out;
                ++start1;
            }
            while(*start2 < *start1 &&
                   start1 != end1   &&
                   start2 != end2)
            {
                *out = *start2;
                ++out;
                ++start2;
            }            
        }
        else if (start1 != end1)
        {
            while(start1 != end1)
            {
                *out = *start1;
                ++out;
                ++start1; 
            }
        }
        else if (start2 != end2)
        {
            while(start2 != end2)
            {
                *out = *start2;
                ++out;
                ++start2; 
            }
        }
        else
        {
            done = true;
        }
    }
}

void mergesort_test();
}

#endif
