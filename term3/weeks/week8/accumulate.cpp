#include <iostream>

using namespace std;


template<typename T>
T accumulate(T val)
{
    return val += 0;
}

template<typename T, typename... args>
T accumulate(T val, args... kwargs)
{
    return val += accumulate(kwargs ...);
}

int main()
{
    cout << accumulate(5) << endl;             // expected: 5
    cout << accumulate(5, -3) << endl;     // expected: -2
    cout << accumulate(5.1, -3.1, 2.0) << endl;// expected: 4
}