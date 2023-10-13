#include <cassert>

template<unsigned N>
double apply(double (*f)(double), double x)
{
    for (unsigned i = 0; i < N; ++i)
        x = f(x);

    return x;

}

double sqr(double x)
{
    return x * x;
}

int main()
{
    assert(1.0 == apply<3>(sqr, 1.0));
    assert(256.0 == apply<3>(sqr, 2.0));
    return 0;
}