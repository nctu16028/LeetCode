#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    vector<string> rows(numRows, "");
    int insert_row = 0;
    int step = 1;   // 1: downward; -1: upward
    for (int i = 0; i < s.length(); i++)
    {
        rows[insert_row] += s[i];
        insert_row += step;
        if (insert_row == numRows - 1 || insert_row == 0)
            step = -step;
    }

    string output = "";
    for (int i = 0; i < numRows; i++)
        output += rows[i];

    return output;
}

int main()
{
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << convert(s, numRows) << endl;

    return 0;
}
