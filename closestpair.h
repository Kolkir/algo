#ifndef _CLOSESTPAIR_H_

#include <stddef.h>
#include <vector>

namespace algo
{
struct Point
{
    double x;
    double y;

    Point();
    Point(std::initializer_list<double> coords);
};
 
bool operator<(const Point& a, const Point& b);

bool operator!=(const Point& a, const Point& b);

double dist(const Point& a, const Point& b);

double ClosestPairB(std::vector<Point>::const_iterator start,
                    std::vector<Point>::const_iterator end, 
                    size_t& count, Point& p1, Point& p2);

double ClosestPair(std::vector<Point>::const_iterator start,
                   std::vector<Point>::const_iterator end,
                   size_t& count,
                   Point& p1, Point& p2);

void closestpair_test();

}

#endif
