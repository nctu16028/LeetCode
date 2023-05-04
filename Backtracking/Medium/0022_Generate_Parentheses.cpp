#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recursiveHelper(int numOfLeft, int numOfRight, string str, vector<string>& parens, const int& n)
{
    if (str.length() == 2 * n)
    {
        parens.push_back(str);
        return;
    }

    if (numOfLeft < n)
        recursiveHelper(numOfLeft + 1, numOfRight, str + "(", parens, n);
    if (numOfRight < numOfLeft)
        recursiveHelper(numOfLeft, numOfRight + 1, str + ")", parens, n);
}

vector<string> generateParenthesis(int n)
{
    vector<string> output;
    string str = "";
    recursiveHelper(0, 0, str, output, n);

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);
    cout << "[\"" << ans[0] << "\"";
    for (int i = 1; i < ans.size(); i++)
        cout << ", \"" << ans[i] << "\"";
    cout << "]" << endl;

    return 0;
}
