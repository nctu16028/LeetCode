#include <iostream>
#include <string>
using namespace std;

int countGoodSubstrings(string s)
{
    int output = 0;
    for (int i = 2; i < s.length(); i++)
    {
        if (s[i-2] != s[i-1] && s[i-2] != s[i] && s[i-1] != s[i])
            output++;
    }

    return output;
}

int main()
{
    string s;
    cin >> s;
    cout << countGoodSubstrings(s) << endl;

    return 0;
}
