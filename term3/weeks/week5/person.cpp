#include <iostream>
#include <utility>

using namespace std;

class Person
{
protected:
    string name_;

public:
    explicit Person(string name) : name_(std::move(name)) {}

    virtual string hello() = 0;
};

class Mister : public Person
{
public:
    explicit Mister(string const &name) : Person(name) {}

    string hello() override
    {
        return "Hello, I am Mister " + name_;
    }
    // Возвращает строку Hello, I am Mister %name_%
};

class Miss : public Person
{
public:
    explicit Miss(string const &name) : Person(name) {}

    string hello() override
    {
        return "Hello, I am Miss " + name_;
    }
    // Возвращает строку Hello, I am Miss %name_%
};

class Professor : public Person
{
private:
    string surname_;

public:
    explicit Professor(string const &name, string surname) : Person(name), surname_(std::move(surname)) {}

    string hello() override
    {
        return "Hello, I am Professor " + surname_;
    }
    // Возвращает строку Hello, I am Professor %surname_%
};


int main()
{
    Professor prof = Professor("Grigory", "Ivanov");
    Miss miss = Miss("Anna");
    Mister mister = Mister("Pedro");

    cout << prof.hello() << endl;  // "Hello, I am Professor Ivanov"
    cout << miss.hello() << endl;  // "Hello, I am Miss Anna"
    cout << mister.hello() << endl;  // "Hello, I am Mister Pedro"
    return 0;
}