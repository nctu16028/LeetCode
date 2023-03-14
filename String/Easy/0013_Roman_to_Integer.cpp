#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s)
{
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I')
        {
            if (i+1 < s.length() && s[i+1] == 'V')
            {
                val += 4;
                i++;
            }
            else if (i+1 < s.length() && s[i+1] == 'X')
            {
                val += 9;
                i++;
            }
            else
                val++;
        }
        else if (s[i] == 'V')
        {
            val += 5;
        }
        else if (s[i] == 'X')
        {
            if (i+1 < s.length() && s[i+1] == 'L')
            {
                val += 40;
                i++;
            }
            else if (i+1 < s.length() && s[i+1] == 'C')
            {
                val += 90;
                i++;
            }
            else
                val += 10;
        }
        else if (s[i] == 'L')
        {
            val += 50;
        }
        else if (s[i] == 'C')
        {
            if (i+1 < s.length() && s[i+1] == 'D')
            {
                val += 400;
                i++;
            }
            else if (i+1 < s.length() && s[i+1] == 'M')
            {
                val += 900;
                i++;
            }
            else
                val += 100;
        }
        else if (s[i] == 'D')
        {
            val += 500;
        }
        else if (s[i] == 'M')
        {
            val += 1000;
        }
    }

    return val;
}

int main()
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;

    return 0;
}
