#include <iostream>

using namespace std;


struct Point
{
    int const x, y;

public:

    Point(): x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}


    Point minx(const Point &rha) const
    {
        return {min(x, rha.x), y};
    }

    Point maxx(const Point &rha) const
    {
        return {max(x, rha.x), y};
    }

    Point miny(const Point &rha) const
    {
        return {x, min(y, rha.y)};
    }

    Point maxy(const Point &rha) const
    {
        return {x, max(y, rha.y)};
    }
};