#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

class Dice
{
public:

    Dice() = default;
    Dice(unsigned max, unsigned seed) : rang(seed), dstr(1, max) {}

    virtual unsigned choice() const
    {
        return dstr(rang);
    }

private:

    mutable default_random_engine rang;
    mutable uniform_int_distribution<unsigned> dstr;
};


class DiceWithBonus : public Dice
{
public:
    DiceWithBonus(unsigned max, unsigned seed): rang(seed), dstr(1, max), max(max) { }

    unsigned choice() const override
    {
        return min(max, dstr(rang) + 1);
    }

private:
    mutable default_random_engine rang;
    mutable uniform_int_distribution<unsigned> dstr;
    unsigned const max;
};