#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Array
{
private:
    size_t m_size = 0;
    T *m_storage = nullptr;

// Приватный метод для упрощения перемещения
    void swap(Array<T> &other)
    {
        T *tmp_storage = new T[other.m_size];
        size_t tmp_size = other.m_size;
        for (size_t i = 0; i < other.m_size; ++i)
            tmp_storage[i] = other.m_storage[i];

        delete[] other.m_storage;
        other.m_size = m_size;
        other.m_storage = new T[m_size];
        for (size_t i = 0; i < m_size; ++i)
            other.m_storage[i] = m_storage[i];

        delete[] m_storage;
        m_size = tmp_size;
        m_storage = new T[tmp_size];
        for (size_t i = 0; i < tmp_size; ++i)
            m_storage[i] = tmp_storage[i];

        delete[] tmp_storage;
    };  // Приватный метод для упрощения перемещения

public:
    // Конструктор
    explicit Array(size_t size = 0, const T &value = T()) : m_size(size), m_storage(new T[size])
    {
        for (size_t i = 0; i < m_size; ++i)
            m_storage[i] = value;
    }

    // Копирующий конструктор
    Array(const Array<T> &other) : m_size(other.m_size), m_storage(new T[m_size])
    {
        for (size_t i = 0; i < m_size; ++i)
            m_storage[i] = other.m_storage[i];
    }

    // Деструктор
    ~Array()
    {
        delete[] m_storage;
    }

    // Оператор копирующего присваивания
    Array &operator=(Array<T> &other)
    {
        if (this != &other)
            swap(other);

        return *this;
    }

    // Перемещающий конструктор
    Array(Array<T> &&other) noexcept
    {
        swap(other);
    }

    // Перемещающий оператор присваивания
    Array &operator=(Array<T> &&other) noexcept
    {
        swap(other);
        return *this;
    }

    // Возвращает размер массива
    [[nodiscard]] size_t size() const
    {
        return m_size;
    }

    // Возвращает idx элемент массива
    T &operator[](size_t idx)
    {
        return m_storage[idx];
    }
};