#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s)
{
    // Try to match each ')' with its nearest valid '('
    int n = s.length();
    vector<int> matchTable(n, -1);
    stack<int> leftParenthesesIndex;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            leftParenthesesIndex.push(i);
        else if (s[i] == ')' && !leftParenthesesIndex.empty())
        {
            matchTable[i] = leftParenthesesIndex.top();
            matchTable[leftParenthesesIndex.top()] = i;
            leftParenthesesIndex.pop();
        }
    }

    // Find the longest substring of matched parentheses
    int output = 0, len = 0;
    for (int i = 0; i < n; i++)
    {
        if (matchTable[i] == -1)
            len = 0;
        else
        {
            len++;
            output = max(output, len);
        }
    }

    return output;
}

int main()
{
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;

    return 0;
}
