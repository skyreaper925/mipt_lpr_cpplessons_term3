#include <iostream>

using namespace std;


template <typename T, size_t arr_size>
void read_array(T* arr)
{
    for (size_t i = 0; i < arr_size; ++i)
        cin >> arr[i];
}


template <typename T, size_t arr_size>
T array_sum (T const *arr)
{
    T sum = 0;
    for (size_t i = 0; i < arr_size; ++i)
        sum += arr[i];

    return sum;
}

int main()
{
    size_t const arr_size = 5;
    auto *arr_d = new double[arr_size];
    read_array(arr_d);
    delete[] arr_d;
    return 0;
}