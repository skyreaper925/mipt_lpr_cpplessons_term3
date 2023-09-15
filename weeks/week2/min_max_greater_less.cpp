#include <iostream>

using namespace std;

template <typename T>
T min (T &first, T &second)
{
    return first > second ? second : first;
}

template <typename T>
T max (T &first, T &second)
{
    return first > second ? first : second;
}

template <typename T>
bool greater (T &first, T &second)
{
    return first > second;
}

template <typename T>
bool less (T &first, T &second)
{
    return first < second;
}

int main()
{
    std::qsort();
    return 0;
}
