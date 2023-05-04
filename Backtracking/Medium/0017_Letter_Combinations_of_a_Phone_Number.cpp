#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recursiveHelper(int i, string letters, vector<string>& combinations, const vector<string>& mapping, const string& digits)
{
    if (i == digits.length())
    {
        combinations.push_back(letters);
        return;
    }

    int num = digits[i] - '0';
    for (int j = 0; j < mapping[num].length(); j++)
        recursiveHelper(i + 1, letters + mapping[num][j], combinations, mapping, digits);
}

vector<string> letterCombinations(string digits)
{
    vector<string> output;
    if (digits.length() > 0)
    {
        vector<string> mapping({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string letters = "";
        recursiveHelper(0, letters, output, mapping, digits);
    }

    return output;
}

int main()
{
    string digits;
    cin >> digits;

    vector<string> ans = letterCombinations(digits);
    cout << "[";
    if (!ans.empty())
    {
        cout << "\"" << ans[0] << "\"";
        for (int i = 1; i < ans.size(); i++)
            cout << ", \"" << ans[i] << "\"";
    }
    cout << "]" << endl;

    return 0;
}
