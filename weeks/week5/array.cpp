#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Array
{
//     Список операций:
public:
    explicit Array(size_t size = 0, const T &value = T())
    {
        size_ = size;
        array = new T[size_];
        for (size_t i = 0; i < size_; ++i)
        {
            array[i] = value;
        }
    }

    Array(const Array &other)
    {
        size_ = other.size_;
        array = new T[other.size_];
        for (size_t i = 0; i < size_; ++i)
            array[i] = other.array[i];

    }

    ~Array()
    {
        delete[] array;
    }

//    деструктор, если он вам необходим.

    Array &operator=(Array *other)
    {
        if (this != &other)
        {
            delete[] this->array;
            this->size_ = other->size_;
            this->array = new T[this->size_];
            for (size_t i = 0; i < size_; ++i)
                this->array[i] = other->array[i];
        }
        return *this;
    }

    size_t size() const
    {
        return size_;
    }

    T &operator[](size_t i)
    {
        return array[i];
    }

    const T &operator[](size_t i) const
    {
        return array[i];
    }

//    две версии оператора доступа по индексу.
//    Операторы ввода-вывода

    template<typename A>
    friend std::ostream &operator<<(std::ostream &out, const Array &obj);

    template<typename A>
    friend std::istream &operator>>(std::istream &in, const Array &obj);


    size_t size_;
    T *array;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &obj)
{
    if (obj.size() > 0)
    {
        out << "[";
        out << obj.array[0];
        for (size_t i = 1; i < obj.size(); ++i)
        {
            out << ", " << obj.array[i];
        }
        out << "]";
    }
    return out;
}

template<typename T>
std::istream &operator>>(std::istream &in, const Array<T> &obj)
{
    for (size_t i = 0; i < obj.size(); ++i)
    {
        in >> obj.array[i];
    }

    return in;
}
