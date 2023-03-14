#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    int prefix_len = 0;
    while (true)
    {
        if (strs.size() == 1)
        {
            prefix_len = strs[0].length();
            break;
        }

        bool flag;
        for (int i = 1; i < strs.size(); i++)
        {
            flag = (prefix_len < strs[i-1].length() && prefix_len < strs[i].length() && strs[i-1][prefix_len] == strs[i][prefix_len]);
            if (!flag)
                break;
        }

        if (flag)
            prefix_len++;
        else
            break;
    }

    return strs[0].substr(0, prefix_len);
}

int main()
{
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}
