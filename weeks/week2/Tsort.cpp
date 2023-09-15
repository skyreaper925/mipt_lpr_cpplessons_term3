#include <iostream>

using namespace std;

template <typename T>
void swap(T* lha, T* rha)
{
    T tmp = *lha;
    *lha = *rha;
    *rha = tmp;
}

template <typename T>
void quick_sort(T* arr, size_t arr_size)
{
    auto left = 0;
    auto right = arr_size;
    auto pivot = arr[arr_size / 2];
    while (left <= right)
    {
        while (arr[left] < pivot)
            ++left;

        while (arr[right] > pivot)
            --right;

        if (left <= right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    if (right > 0)
        quick_sort(arr, right + 1);

    if (left < arr_size)
        quick_sort(arr + left, arr_size - left);

}


int main()
{
    int *arr = new int [] {3, 2, 1};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, arr_size);

    for (size_t i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";

    cout << endl;

    delete [] arr;
    return 0;
}
