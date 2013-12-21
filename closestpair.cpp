#include "closestpair.h"

#include <algorithm>
#include <iostream>
#include <cassert>

namespace algo
{

Point::Point()
	: x(0)
	, y(0)
{
}

Point::Point(std::initializer_list<double> coords)
{
	assert(coords.size() == 2);
	x = *coords.begin();
	y = *std::next(coords.begin());
}
 
bool operator< (const Point& a, const Point& b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    else
    {
        return a.y < b.y;
    }
}

bool operator!= (const Point& a, const Point& b)
{
    return a.x != b.x || a.y != b.y;
}

double dist(const Point& a, const Point& b)
{
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double ClosestPairB(std::vector<Point>::const_iterator start,
                    std::vector<Point>::const_iterator end, 
                    size_t& count, Point& p1, Point& p2)
{
    Point a;
    Point b;
    double minD = std::numeric_limits<int>::max();

    std::for_each(start, end,
        [&](const Point& p)
    {
        std::for_each(start, end,
            [&](const Point& pp)
        {
            if (p != pp)
            {
                auto d = dist(p, pp);
                if (d < minD)
                {
                    minD = d;
                    a = p;
                    b = pp;
                }
                ++count;
            }
        });
    });

    p1 = a;
    p2 = b;
    return minD;
}

double ClosestPair(std::vector<Point>::const_iterator start,
                   std::vector<Point>::const_iterator end,
                   size_t& count,
                   Point& p1, Point& p2)
{
    auto len = std::distance(start, end);
    if (len <= 3)
    {
        return ClosestPairB(start, end, count, p1, p2);
    }
    else
    {
        auto splitPos = len / 2;
        auto l = start;
        auto r = start;
        std::advance(r, splitPos);

        Point l1, l2, r1, r2;
        double dl = ClosestPair(l, r, count, l1, l2);
        double dr = ClosestPair(r, end, count, r1, r2);

        double minD = std::min(dl, dr);
        if (minD == dl)
        {
            p1 = l1;
            p2 = l2;
        }
        else
        {
            p1 = r1;
            p2 = r2;
        }

        auto middleX = (std::prev(r)->x + r->x) / 2;
        l = std::lower_bound(start, end, Point{ middleX - minD, 0 });
        r = std::upper_bound(start, end, Point{ middleX + minD, 0 });

        auto d = ClosestPairB(l, r, count, l1, l2);

        if (d < minD)
        {
            minD = d;
            p1 = l1;
            p2 = l2;
        }
        return minD;
    }
}

void closestpair_test()
{
    std::vector<Point> m = { { 2,  7  },
                             { 4,  13 },
                             { 5,  7  },
                             { 10, 5  },
                             { 13, 9  },
                             { 15, 5  },
                             { 17, 7  },
                             { 19, 10 },
                             { 22, 7  },
                             { 25, 10 },
                             { 29, 14 },
                             { 30, 2  } };
    
    size_t count = 0;

    Point p1, p2;
    double minD = ClosestPairB(m.begin(), m.end(), count, p1, p2);

    std::cout << "Bruteforce: " << count << std::endl;
    std::cout << "Min = " << minD << std::endl;

    std::sort(m.begin(), m.end());

    Point p3, p4;
    count = 0;
    minD = 0;

    minD = ClosestPair(m.begin(), m.end(), count, p3, p4);
    
    std::cout << "Divide: " << count << std::endl;
    std::cout << "Min = " << minD << std::endl;
}
}