#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasAllCodes(string s, int k)
{
    vector<bool> flag((1 << k), false);
    int count = 0;

    int hashValue = stoi(s.substr(0, k), nullptr, 2);
    flag[hashValue] = true;
    count++;

    for (int i = k; i < s.length(); i++)
    {
        hashValue = (hashValue << 1) - ((s[i-k] == '1') << k) + (s[i] == '1');
        if (!flag[hashValue])
        {
            flag[hashValue] = true;
            count++;
        }
    }

    return count == (1 << k);
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << (hasAllCodes(s, k) ? "true" : "false") << endl;

    return 0;
}
