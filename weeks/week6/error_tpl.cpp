#include <cassert>

template<>
int error_tpl<int>(int const &a)
{
    return a;
}

int main()
{
    auto a = 2;
    assert(a == error_tpl(static_cast<int>(a));
    return 0;
}