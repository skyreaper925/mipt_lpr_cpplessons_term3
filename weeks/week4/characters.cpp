#include <iostream>

using namespace std;

struct Character
{
    string const & name() const;
    unsigned health() const;
};

struct LongRange : public Character
{
    string const & name() const;
    unsigned health() const;

    unsigned range() const;
};

struct SwordsMan : public Character
{
    string const & name() const;
    unsigned health() const;

    unsigned strength() const;
};

struct Wizard : public LongRange
{
    string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned mana() const;
};

struct Archer : public LongRange
{
    string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned accuracy() const;
};