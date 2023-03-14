#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> groups;
    for (int i = 0; i < strs.size(); i++)
    {
        // Use the sorted string as the key of a group
        string str_sorted = strs[i];
        sort(str_sorted.begin(), str_sorted.end());
        if (groups.count(str_sorted) == 0)
            groups.insert({str_sorted, vector<string>()});
        groups[str_sorted].push_back(strs[i]);
    }

    // Pack all the groups into a list
    vector<vector<string>> output;
    for (auto kv : groups)
        output.push_back(kv.second);

    return output;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        getline(cin, strs[i]);

    vector<vector<string>> ans = groupAnagrams(strs);
    cout << "[";
    cout << "[\"" << ans[0][0] << "\"";
    for (int j = 1; j < ans[0].size(); j++)
        cout << ", \"" << ans[0][j] << "\"";
    cout << "]";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ", [\"" << ans[i][0] << "\"";
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", \"" << ans[i][j] << "\"";
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
