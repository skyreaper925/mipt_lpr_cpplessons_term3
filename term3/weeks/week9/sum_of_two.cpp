#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> twoSum(const vector<int> &nums, int target)
{
    // your code
    unordered_map<int, int> counts;

    for (auto i = 0; i < nums.size(); ++i)
        counts[nums[i]] = i;

    vector<pair<int, int>> values;
    for (auto pair: counts)
        values.emplace_back(pair);

    sort(values.begin(), values.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });

    auto lidx = 0;
    auto ridx = nums.size() - 1;
    while (lidx < ridx)
    {
        int res = values[lidx].first + values[ridx].first;
        if (res < target)
            lidx++;

        else if (res > target)
            ridx--;

        else
            return make_pair(values[lidx].second, values[ridx].second);
    }
    // Если нужно вернуть значения как пару индексов
    return make_pair(-1, -1);
}