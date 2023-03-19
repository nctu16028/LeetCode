#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp_table(m);
    for (int i = 0; i < m; i++)
        dp_table[i] = vector<int>(n, INT_MAX);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                dp_table[i][j] = grid[i][j];
            else if (i == m - 1)
                dp_table[i][j] = grid[i][j] + dp_table[i][j + 1];
            else if (j == n - 1)
                dp_table[i][j] = grid[i][j] + dp_table[i + 1][j];
            else
                dp_table[i][j] = grid[i][j] + min(dp_table[i][j + 1], dp_table[i + 1][j]);
        }
    }

    return dp_table[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m);
    for (int i = 0; i < m; i++)
    {
        grid[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << minPathSum(grid) << endl;

    return 0;
}
