#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> charMapping;
    unordered_set<char> valueSet;
    for (int i = 0; i < s.length(); i++)
    {
        if (charMapping.count(s[i]) == 0)
        {
            if (valueSet.count(t[i]) == 1)
                return false;
            charMapping.insert({s[i], t[i]});
            valueSet.insert(t[i]);
        }
        else if (charMapping[s[i]] != t[i])
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << (isIsomorphic(s, t) ? "true" : "false") << endl;

    return 0;
}
