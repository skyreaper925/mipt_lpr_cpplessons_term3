#include <iostream>
#include <cmath>

using namespace std;

struct StructBall
{
    int x, y, z, r;
};


class ClassBall
{
private:
    int x = 1, y = 2, z = 3;
    int r_squared;

    double calcVolume() const
    {
        return 4. * r * r_squared;
    }

public:
//    ClassBall(int x, int y, int z, int r) : x(x), y(y), z(z), r(r), r_squared(r*r) {};

    void print() const
    {
        cout << x << ' ' << y << ' ' << z << endl;
        cout << "Volume of the ball is" << ' ' << calcVolume() << endl;
    }

    void move(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->y = y;

    }

    int r;
};

int main()
{
    ClassBall ball1;
    cin >> ball1.r;
    ball1.print();
    return 0;
}
