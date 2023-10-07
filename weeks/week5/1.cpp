#include <iostream>

using namespace std;

template<typename T>
class Base
{
public:
    Base() { cout << "Base" << endl; }

    T field;
};

//struct Derived : Base
//{
//public:
//    void hello() override { cout << "Hello" << endl; }
//};

int main()
{
    auto b = Base<double>();
    cout << sizeof(b.field) << endl;
    return 0;
}

