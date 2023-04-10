#include <iostream>
#include <vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dpTable(m, vector<int>(n));     // dpTable[i][j] means the minimum HP the knight must have before entering grid (i, j)

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                dpTable[i][j] = 1 - dungeon[i][j];
            else if (i == m - 1)
                dpTable[i][j] = dpTable[i][j + 1] - dungeon[i][j];
            else if (j == n - 1)
                dpTable[i][j] = dpTable[i + 1][j] - dungeon[i][j];
            else
                dpTable[i][j] = min(dpTable[i][j + 1], dpTable[i + 1][j]) - dungeon[i][j];
            dpTable[i][j] = (dpTable[i][j] < 1) ? 1 : dpTable[i][j];    // the minimum HP cannot be lower than 1
        }
    }

    return dpTable[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dungeon(m);
    for (int i = 0; i < m; i++)
    {
        dungeon[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> dungeon[i][j];
    }
    cout << calculateMinimumHP(dungeon) << endl;

    return 0;
}
