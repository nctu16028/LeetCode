#include <iostream>
#include <string>
using namespace std;

// Recurrence relation for reference
/*bool isMatch(string s, string p)
{
    if (p.length() == 0)
        return (s.length() == 0);
    else if (p.length() == 1)
    {
        if (s.length() != 1)
            return false;
        else if (p[0] == '.')
            return true;
        else
            return (s[0] == p[0]);
    }
    else
    {
        if (p[0] == '.' && p[1] == '*')
            return (isMatch(s, p.substr(2)) || (s.length() > 0 && isMatch(s.substr(1), p)));
        else if (p[1] == '*')
            return (isMatch(s, p.substr(2)) || (s.length() > 0 && s[0] == p[0] && isMatch(s.substr(1), p)));
        else if (p[0] == '.')
            return (s.length() > 0 && isMatch(s.substr(1), p.substr(1)));
        else
            return (s.length() > 0 && s[0] == p[0] && isMatch(s.substr(1), p.substr(1)));
    }
}*/

bool isMatch(string s, string p)
{
    int ns = s.length();
    int np = p.length();
    s = "_" + s;
    p = "_" + p;

    // dp_table[i][j] indicates whether s[1..j] matches p[1..i], where i = 0 or j = 0 means empty string
    bool dp_table[20+1][20+1];
    for (int i = 0; i <= np ; i++)
    {
        if (i+1 <= np && p[i+1] == '*')
            continue;
        for (int j = 0; j <= ns; j++)
        {
            if (i == 0)
                dp_table[i][j] = (j == 0) ? true : false;
            else if (p[i] == '*' && p[i-1] == '.')
                dp_table[i][j] = dp_table[i-2][j] || (j > 0 && dp_table[i][j-1]);
            else if (p[i] == '*')
                dp_table[i][j] = dp_table[i-2][j] || (j > 0 && s[j] == p[i-1] && dp_table[i][j-1]);
            else if (p[i] == '.')
                dp_table[i][j] = (j > 0) && dp_table[i-1][j-1];
            else
                dp_table[i][j] = (j > 0) && (s[j] == p[i]) && dp_table[i-1][j-1];
        }
    }

    return dp_table[np][ns];
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "true" : "false") << endl;

    return 0;
}
