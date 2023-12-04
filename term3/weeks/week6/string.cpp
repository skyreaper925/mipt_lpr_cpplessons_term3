#pragma once

#include <iostream>

using namespace std;

class String
{
private:
    size_t m_size = 0;
    char *m_storage = nullptr;

    // Меняет местами параметры входной строки и исходной
    // Полезна для избежания копий кода
    void swap(String &other)
    {
        auto tmp_storage = new char[other.m_size];
        size_t tmp_size = other.m_size;
        for (size_t i = 0; i < other.m_size; ++i)
            tmp_storage[i] = other.m_storage[i];

        delete[] other.m_storage;
        other.m_size = m_size;
        other.m_storage = new char[m_size];
        for (size_t i = 0; i < m_size; ++i)
            other.m_storage[i] = m_storage[i];

        delete[] m_storage;
        m_size = tmp_size;
        m_storage = new char[tmp_size];
        for (size_t i = 0; i < tmp_size; ++i)
            m_storage[i] = tmp_storage[i];

        delete[] tmp_storage;
    };

    // Устанавливает единичный элемент для всех значений в массиве
    // Полезна для избежания копий кода
    void assign_element(char &el)
    {
        for (size_t i = 0; i < m_size; ++i)
            m_storage[i] = el;
    }

public:
    // Конструктор
    explicit String(size_t size = 0, char el = 'a') : m_size(size), m_storage(new char[m_size])
    {
        assign_element(el);
    }

    // Копирующий конструктор
    String(const String &other) : m_size(other.m_size), m_storage(new char[m_size])
    {
        for (size_t i = 0; i < m_size; ++i)
            m_storage[i] = other.m_storage[i];
    }

    // Деструктор
    ~String()
    {
        delete[] m_storage;
    }

    // Оператор копирующего присваивания
    String &operator=(String &other)
    {
        if (this != &other)
            swap(other);

        return *this;
    }

    String(String &&other) noexcept: m_size(0), m_storage(nullptr)
    {
        swap(other);
    }

    // Оператор перемещающего присваивания
    String &operator=(String &&other) noexcept
    {
        if (this != &other)
            swap(other);
        return *this;
    }

    // Оператор +=
    String &operator+=(const String &other)
    {
        auto new_size = m_size + other.m_size;
        auto *new_storage = new char[new_size];

        for (size_t i = 0; i < m_size; ++i)
            new_storage[i] = m_storage[i];

        for (size_t i = 0; i < other.m_size; ++i)
            new_storage[m_size + i] = other.m_storage[i];

        delete[] m_storage;
        m_size = new_size;
        m_storage = new_storage;

        return *this;
    }

    // Внешний оператор сложения
    friend String operator+(String const &lha, String const &rha)
    {
        String res(lha);
        return res += rha;
    }

    // Возвращает размер строки
    [[nodiscard]] size_t size() const
    {
        return m_size;
    }

    // Возвращает элемент строки с индексом idx
    char &operator[](size_t idx)
    {
        return m_storage[idx];
    }

    // Операторы ввода-вывода
    friend std::ostream &operator<<(std::ostream &out, const String &obj)
    {
        for (size_t i = 0; i < obj.size(); ++i)
            out << obj.m_storage[i];

        return out;
    }

    friend std::istream &operator>>(std::istream &in, const String &obj)
    {
        for (size_t i = 0; i < obj.size(); ++i)
            in >> obj.m_storage[i];

        return in;
    }
};