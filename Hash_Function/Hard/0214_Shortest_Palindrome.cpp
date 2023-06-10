#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s)
{
    if (s.length() < 2)
        return s;

    const long long int HASH_BASE = 27;
    const long long int MOD = 1e9 + 7;

    // Calculate the hash value of original string
    long long int forwardHash = 0;
    long long int basePow = 1;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        forwardHash = (forwardHash * HASH_BASE + (s[i] - 'a' + 1)) % MOD;
        basePow = basePow * HASH_BASE % MOD;
    }

    // Calculate the hash value of reversed string
    long long int backwardHash = 0;
    for (int i = s.length() - 1; i >= 0; i--)
        backwardHash = (backwardHash * HASH_BASE + (s[i] - 'a' + 1)) % MOD;

    if (forwardHash == backwardHash)
        return s;

    // Rolling hash
    int addStart = 1;
    long long int upperHash = 0, lowerHash = 0;
    long long int lowerBasePow = 1;
    for (int i = s.length() - 1; i > 0; i--)
    {
        upperHash = (upperHash * HASH_BASE + (s[i] - 'a' + 1)) % MOD;
        lowerHash = ((s[i] - 'a' + 1) * lowerBasePow + lowerHash) % MOD;
        lowerBasePow = lowerBasePow * HASH_BASE % MOD;
        if ((upperHash * basePow + forwardHash) % MOD == (backwardHash * lowerBasePow + lowerHash) % MOD)
        {
            addStart = i;
            break;
        }
    }

    string adder = s.substr(addStart);
    reverse(adder.begin(), adder.end());
    return adder + s;
}

int main()
{
    string s;
    cin >> s;
    cout << shortestPalindrome(s) << endl;

    return 0;
}
