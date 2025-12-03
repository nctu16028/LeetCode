#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                matrix[i][j] += min(matrix[i - 1][j], matrix[i - 1][j + 1]);
            else if (j == n - 1)
                matrix[i][j] += min(matrix[i - 1][j - 1], matrix[i - 1][j]);
            else
                matrix[i][j] += min(min(matrix[i - 1][j - 1], matrix[i - 1][j]), matrix[i - 1][j + 1]);
        }
    }

    int output = INT_MAX;
    for (int j = 0; j < n; j++)
        output = min(output, matrix[n - 1][j]);

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << minFallingPathSum(matrix) << endl;

    return 0;
}
