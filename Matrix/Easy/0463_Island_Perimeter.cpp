#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = grid[0].size();
    int output = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 0)
                continue;

            if (i == 0 || (i > 0 && grid[i - 1][j] == 0))
                output++;
            if (i == row - 1 || (i < row - 1 && grid[i + 1][j] == 0))
                output++;
            if (j == 0 || (j > 0 && grid[i][j - 1] == 0))
                output++;
            if (j == col - 1 || (j < col - 1 && grid[i][j + 1] == 0))
                output++;
        }
    }

    return output;
}

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid(row);
    for (int i = 0; i < row; i++)
    {
        grid[i] = vector<int>(col);
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];
    }
    cout << islandPerimeter(grid) << endl;

    return 0;
}
