#include <iostream>

template<typename T>
auto Id(T base)
{
    std::cout << "Id called!" << std::endl;
    return base;
}

// здесь ваш код шаблона класса и его специализаций
template<typename T, unsigned N>
struct TPow final
{
    TPow(T base) : base(base) {}

    auto operator()() const
    {
        return base * TPow<T, N - 1>(base)();
    }

    T base;
};

template<typename T>
struct TPow<T, 1>
{
    TPow(T base) : base(base) {}

    auto operator()() const
    {
        return Id(base);
    }

    T base;
};


int main()
{
    TPow<int, 2> powA(2), powB(3);
    std::cout << powA() << std::endl;
    std::cout << powB() << std::endl;
    TPow<double, 3> powC(2.0);
    std::cout << powC() << std::endl;
    return 0;
}