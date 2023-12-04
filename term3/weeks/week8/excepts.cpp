#include <iostream>

using namespace std;

class SomeClass
{
};

void process(int x)
{
    try
    {
        switch (x)
        {
            case 1:
                throw 42;
            case 2:
                throw "problem";
            case 3:
                throw SomeClass();
        }
    }

    catch (int ex)
    {
        cout << "int error" << endl;
    }
    catch (const char *ex)
    {
        cout << "problem" << endl;
    }
    catch (const SomeClass ex)
    {
        cout << "SomeClass() problem" << endl;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
    }
}


int main()
{
    for (int i = 0; i != 4; ++i)
        process(i);

    cout << "okay" << endl;
    return 0;
}