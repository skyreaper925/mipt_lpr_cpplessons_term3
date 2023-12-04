#include <iostream>

using namespace std;


template <typename T, size_t arr_size>
T array_sum (T const *arr)
{
    T sum = 0;
    for (size_t i = 0; i < arr_size; ++i)
        sum += arr[i];

    return sum;
}

int main() {
    int arr[12] = {1, 0, 2, -1, 3, -2, 4, -5, 6, -7, 8, -9};
    array_sum(arr);
    return 0;
}