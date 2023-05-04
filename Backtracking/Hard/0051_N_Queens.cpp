#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recursiveHelper(int currRow, vector<int>& row2Col, vector<vector<int>>& solutions)
{
    if (currRow == row2Col.size())
    {
        solutions.push_back(row2Col);
        return;
    }

    for (int j = 0; j < row2Col.size(); j++)
    {
        // Check whether column j is valid for the current row
        bool flag = true;
        for (int i = 0; i < currRow; i++)
        {
            if (j == row2Col[i] || j + (currRow - i) == row2Col[i] || j - (currRow - i) == row2Col[i])
            {
                flag = false;
                break;
            }
        }

        // If column j is valid, go on to the next row
        if (flag)
        {
            row2Col[currRow] = j;
            recursiveHelper(currRow + 1, row2Col, solutions);
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> solutions;
    vector<int> row2Col(n);
    recursiveHelper(0, row2Col, solutions);

    vector<vector<string>> output;
    for (int i = 0; i < solutions.size(); i++)
    {
        vector<string> board(n, string(n, '.'));
        for (int row = 0; row < n; row++)
            board[row][solutions[i][row]] = 'Q';
        output.push_back(board);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);
    cout << "[";
    if (!ans.empty())
    {
        cout << "[\"" << ans[0][0] << "\"";
        for (int j = 1; j < n; j++)
            cout << ", \"" << ans[0][j] << "\"";
        cout << "]";
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ", [\"" << ans[i][0] << "\"";
            for (int j = 1; j < n; j++)
                cout << ", \"" << ans[i][j] << "\"";
            cout << "]";
        }
    }
    cout << "]" << endl;

    return 0;
}
