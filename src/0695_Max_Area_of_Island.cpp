#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
    int area = 1;
    visited[i][j] = true;
    if (i > 0 && grid[i - 1][j] == 1 && !visited[i - 1][j])
        area += dfs(grid, visited, i - 1, j);
    if (i < grid.size() - 1 && grid[i + 1][j] == 1 && !visited[i + 1][j])
        area += dfs(grid, visited, i + 1, j);
    if (j > 0 && grid[i][j - 1] == 1 && !visited[i][j - 1])
        area += dfs(grid, visited, i, j - 1);
    if (j < grid[0].size() - 1 && grid[i][j + 1] == 1 && !visited[i][j + 1])
        area += dfs(grid, visited, i, j + 1);
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int output = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                output = max(output, dfs(grid, visited, i, j));
            }
        }
    }

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << maxAreaOfIsland(grid) << endl;

    return 0;
}
