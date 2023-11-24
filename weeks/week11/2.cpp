#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template<typename T>
bool comp(const T &lha, const T &rha)
{
    return lha < rha;
}

int extra_val = 0;

int main()
{
    std::vector<int> vector = {1, 2, 3, -1, -2, -3};
    for (auto el: vector)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    //std::sort(vector.begin(), vector.end(), comp<int>);

    //лямбда функция; [ ] – список захвата, [&] - берет все внешние параметры по ссылке, [=] - захватывание всех
    // параметров копированием. Но если переменная глобальная она всегда захватывается по ссылке
    std::sort(vector.begin(), vector.end(), [=]
                      (const int &lha, const int &rha) {
                  extra_val++;
                  return lha < rha;
              }
            /*struct
            {
                bool operator()(const int& lha, const int& rha) {return lha < rha;}
            };*/

    );
    std::function<bool(const int &lha, const int &rha)> comp0 = [=](const int &lha, const int &rha) {
        ++extra_val;
        return lha < rha;
    };
    auto comp = [=](const int &lha, const int &rha) {
        ++extra_val;
        return lha < rha;
    };

    std::cout << extra_val << std::endl;
    for (auto el: vector)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    return 0;
}