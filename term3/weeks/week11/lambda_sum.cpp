#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

auto lambda_sum = [](auto... args) -> decltype((args + ...)) {
    return (args + ...);
};


int main()
{
    auto result = lambda_sum(2, 3, 4, 5, 5.5, 7.5, 9., -12.5);
    cout << result;
    return 0;
}
