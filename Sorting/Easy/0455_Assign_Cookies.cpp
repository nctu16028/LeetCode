#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int idx_g = 0, idx_s = 0;
    for (; idx_g < g.size() && idx_s < s.size(); idx_s++)
    {
        if (s[idx_s] >= g[idx_g])
            idx_g++;
    }

    return idx_g;
}

int main()
{
    int numChildren, numCookies;
    cin >> numChildren >> numCookies;

    vector<int> children(numChildren);
    for (int i = 0; i < numChildren; i++)
        cin >> children[i];

    vector<int> cookies(numCookies);
    for (int i = 0; i < numCookies; i++)
        cin >> cookies[i];

    cout << findContentChildren(children, cookies);

    return 0;
}
