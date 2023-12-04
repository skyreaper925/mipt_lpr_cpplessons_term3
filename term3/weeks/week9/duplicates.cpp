#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    // your code
    set<int> sett(nums.begin(), nums.end());
    auto i = 0;
    for (auto it = sett.begin(); it != sett.end(); ++it, ++i)
        nums[i] = *it;

    for (; i < nums.size(); ++i)
        nums[i] = '_';

    return static_cast<int> (sett.size());
}