#include <iostream>
#include <string>
using namespace std;

string greatestLetter(string s)
{
    for (char c = 'Z'; c >= 'A'; c--)
    {
        if (s.find(c) != string::npos && s.find(c - 'A' + 'a') != string::npos)
            return string(1, c);
    }

    return string();
}

int main()
{
    string s;
    cin >> s;
    cout << greatestLetter(s) << endl;

    return 0;
}
