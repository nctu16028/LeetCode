#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> output;
    if (p.length() > s.length())
        return output;

    int windowSize = p.length();
    string window = s.substr(0, windowSize);
    sort(p.begin(), p.end());
    sort(window.begin(), window.end());
    if (window == p)
        output.push_back(0);
    for (int i = 1; i <= s.length() - windowSize; i++)
    {
        auto toDelete = lower_bound(window.begin(), window.end(), s[i - 1]);
        window.erase(toDelete);
        auto toInsert = lower_bound(window.begin(), window.end(), s[i + windowSize - 1]);
        window.insert(toInsert, s[i + windowSize - 1]);
        if (window == p)
            output.push_back(i);
    }

    return output;
}

/*vector<int> findAnagrams(string s, string p)
{
    vector<int> output;
    if (p.length() > s.length())
        return output;

    int windowSize = p.length();
    multiset<char> window(s.begin(), s.begin() + windowSize);
    multiset<char> pSet(p.begin(), p.end());
    if (window == pSet)
        output.push_back(0);
    for (int i = 1; i <= s.length() - windowSize; i++)
    {
        auto toDelete = window.lower_bound(s[i - 1]);
        window.erase(toDelete);
        auto toInsert = window.lower_bound(s[i + windowSize - 1]);
        window.insert(toInsert, s[i + windowSize - 1]);
        if (window == pSet)
            output.push_back(i);
    }

    return output;
}*/

int main()
{
    string s, p;
    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);
    cout << "[";
    if (!ans.empty())
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    return 0;
}
