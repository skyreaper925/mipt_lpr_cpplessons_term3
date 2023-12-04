#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// Функция для создания отсортированного хэша имени абитуриента
string getSortedName(const string &str)
{
    auto sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}

vector<vector<string>> groupByName(vector<string> &strs)
{
    unordered_map<string, vector<string>> facultyMap;
    for (const string &name: strs)
    {
        auto sortedName = getSortedName(name);
        facultyMap[sortedName].push_back(name);
    }

    vector<vector<string>> res;
    for (const auto &entry: facultyMap)
        res.push_back(entry.second);

    return res;
}