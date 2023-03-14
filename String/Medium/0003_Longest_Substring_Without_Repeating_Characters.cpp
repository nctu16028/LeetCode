#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.length() < 2)
        return s.length();

    int max_length = 0;
    int start = 0;
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = start; j < i; j++)
        {
            if (s[j] == s[i])
            {
                start = j + 1;
                break;
            }
        }

        if (i - start + 1 > max_length)
            max_length = i - start + 1;
    }

    return max_length;
}

int main()
{
    string s;
    getline(cin, s);
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
