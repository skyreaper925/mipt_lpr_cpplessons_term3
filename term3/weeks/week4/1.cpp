#include <iostream>

using namespace std;

class Base
{
public:
    int base_field = 0;

    Base() { cout << "Base" << endl; };

    Base(int base_value, int protected_base_value) : base_field(base_value), protected_base_field
            (protected_base_value) {};

    virtual void print() const
    {
        cout << "Base: " << base_field << endl;
    }

protected:
    int protected_base_field = 0;
};


class Derived final : public Base
{
public:
    Derived() = default;

    explicit Derived(int derived_value) : derived_field(derived_value) {};

    Derived(int derived_value, int base_value, int protected_base_value) : Base(base_value, protected_base_value),
                                                                           derived_field(derived_value) {};

    void print() const override
    {
        cout << "Derived: " << derived_field << endl;
    }

    int derived_field = 0;
};

int main()
{
    auto base = Base();
    auto derived = Derived();
    Base &base_ref = base;
    Derived &derived_ref = derived;
    base_ref.print();
    derived_ref.print();
    return 0;
}
