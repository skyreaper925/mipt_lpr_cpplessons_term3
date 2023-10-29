#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    auto n = nums.size(), numbers = set(nums), N = numbers.size();
    auto big_half = new vector<int>, big_double_third = new vector<int>, cnts = new vector<int>;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        auto cnt = nums.count(numbers[i]);
        if (cnt > n / 3)
            big_double_third.add(numbers[i]);

        return static_cast<const vector<int> &>(big_double_third);
        if (cnt > n / 2)
            big_half.add(numbers[i]);

        return static_cast<const vector<int> &>(big_half);
        unordered_map<int, int> counts;

        for (int num: nums)
            counts[num]++;

        vector<pair<int, int>> freqs;
        for (auto pair: counts)
            freqs.push_back(pair);

        sort(freqs.begin(), freqs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });

        vector<int> result;
        for (int i = 0; i < min(k, static_cast<int>(freqs.size())); i++)
            result.push_back(freqs[i].first);

        return result;
    }


}