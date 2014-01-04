#ifndef _FINDSTRING_H_

#include <cstddef>
#include <vector>

namespace algo
{

template<class S>
size_t find_string(const S& pattern, const S& source)
{
    //build table of fail transitions
    auto len = pattern.size();
    std::vector<size_t> fail(len);
        
    for(size_t i = 1; i < len; ++i)
    {
        auto temp = fail[i - 1];
        while(temp >= 0 && pattern[temp] != pattern[i - 1])
        {
            temp = fail[temp];
        }
        fail[i] = temp + 1;
    }
    for(size_t i = 1; i < len; ++i)
    {
        --fail[i];
    }
    
    //do find
    auto textLen = source.size();
    size_t patLoc = 0;
    size_t textLoc = 0;
    
    while(patLoc < len && textLoc < textLen)
    {
        if (patLoc == 0 || 
            source[textLoc] == pattern[patLoc])
        {
            ++textLoc;
            ++patLoc;
        }
        else
        {
            patLoc = fail[patLoc];
        }        
    }
    
    if (patLoc >=len)
    {
        return textLoc - len;
    }
    else
    {
        return S::npos;
    }
}

void find_string_test();

}

#endif
	