#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeOuterParentheses(string s)
{
    bool flag = false;
    stack<char> checker;
    string output = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            if (!flag)
                flag = true;
            else
            {
                checker.push(s[i]);
                output += s[i];
            }
        }
        else
        {
            if (checker.empty())
                flag = false;
            else
            {
                checker.pop();
                output += s[i];
            }
        }
    }

    return output;
}

int main()
{
    string s;
    cin >> s;
    cout << removeOuterParentheses(s) << endl;

    return 0;
}
