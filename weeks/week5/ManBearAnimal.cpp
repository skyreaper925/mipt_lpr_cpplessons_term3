#include <iostream>
#include <utility>

using namespace std;

// этот класс уже определён выше
//struct Unit
//{
//    explicit Unit(size_t id) : id_(id) {}
//
//    size_t id() const { return id_; }
//
//private:
//    size_t id_{};
//};

// базовый класс для животных
struct Animal : virtual public Unit
{
    // name хранит название животного
    // "bear" для медведя
    // "pig" для свиньи
    Animal(string const &name, size_t id) : Unit(id), name_(name) {}

    string const &name() const { return name_; }

private:
    string name_;
};

// класс для человека
struct Man : virtual public Unit
{
    explicit Man(size_t id) : Unit(id) {}

//    Man(size_t id) : id_(id) {}
//
//private:
//    size_t id_;
};

// класс для медведя
struct Bear : public Animal
{
    explicit Bear(size_t id) : Unit(id), Animal("bear", id) {}

//    string const &name() const { return name_; }
//
//private:
//    string name_;
//    size_t id;
};

// класс для свиньи
struct Pig : public Animal
{
    explicit Pig(size_t id) : Unit(id), Animal("pig", id) {}

//    string const &name() const { return name_; }
//
//private:
//    string name_;
//    size_t id;
};

// класс для челмедведосвина
struct ManBearPig : public Bear, public Man, public Pig
{
    ManBearPig(size_t id) : Unit(id), Pig(id), Bear(id), Man(id) {}
};