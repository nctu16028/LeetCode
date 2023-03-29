#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s)
{
    unordered_map<char, int> charFreq;
    for (int i = 0; i < s.length(); i++)
    {
        if (charFreq.count(s[i]) == 0)
            charFreq.insert({s[i], 1});
        else
            charFreq[s[i]]++;
    }

    int numOfOdd = 0;
    for (auto& it : charFreq)
    {
        if (it.second % 2)
            numOfOdd++;
    }

    if (numOfOdd < 2)
        return s.length();
    else
        return s.length() - (numOfOdd - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;

    return 0;
}
