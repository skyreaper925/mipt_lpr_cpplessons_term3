#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;


struct Point_3D
{
    double x, y, z;
};


struct Sphere
{
    Point_3D center;
    double R;
};


double distance (Point_3D const &a, Point_3D const &b)
{
    double r = pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);
    return r;
}


Point_3D middle(Point_3D const &a, Point_3D const &b)
{
    return Point_3D{(a.x + b.x) / 2, (a.z + b.z) / 2, (a.z + b.z) / 2};
}


Point_3D center_of_mass(Point_3D const *begin, Point_3D const *end)
{
    size_t n = 0;
    double x_m = 0, y_m = 0, z_m = 0;
    for (Point_3D const *i = begin; i != end; ++i)
    {
        x_m += i->x;
        y_m += i->y;
        z_m += i->z;
    }

    return Point_3D{x_m / n, y_m / n, z_m / n};
}


struct Point_3D_Cloud
{
    Point_3D *points = nullptr;
    unsigned size = 0;
};

Point_3D_Cloud cloud_new(unsigned N)
{
    Point_3D *point = nullptr;
    unsigned i = 0;
    while (i < N)
        i++;

    return Point_3D_Cloud{point, N};
}


void cloud_free(Point_3D_Cloud &cloud)
{
    delete cloud.points;
    cloud.size = 0;
}


Point_3D_Cloud cloud_merge(Point_3D_Cloud const &c1, Point_3D_Cloud const &c2)
{
    auto *c = new Point_3D_Cloud;
    c->size = c1.size + c2.size;
    for (auto i = 0; i < c1.size; ++i)
    {
        c->points = c1.points + i;
    }

    for (auto i = 0; i < c2.size; ++i)
    {
        c->points = c2.points + i;
    }

    return *c;
}


Point_3D* split(Sphere const &s, Point_3D_Cloud &cloud)
{
    for (auto i = 0; i < cloud.size; ++i)
    {
        if (distance(s.center, *(cloud.points+i)) > pow(s.R, 2))
            return cloud.points+i;
    }

    return cloud.points + cloud.size;
}


Point_3D* nearest_point (Point_3D const &p, Point_3D_Cloud &cloud)
{
    auto min_dist = distance(p, *cloud.points);
    auto nearest = cloud.points;
    for (auto i = 0; i < cloud.size; ++i)
    {
        if (distance(p, *(cloud.points+i)) < min_dist)
        {
            min_dist = distance(p, *(cloud.points + i));
            nearest = cloud.points + i;
        }
    }

    return nearest;
}

//void distance_sort (Point_3D const &p, Point_3D_Cloud &cloud)
//{
//    cloud.points = nearest_point()
//}

int main()
{
    const Point_3D *const a = nullptr;
    return 0;
}
