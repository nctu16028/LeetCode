#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int spaceRemained, int end, int& numOfPaths, vector<bool>& visited, const vector<vector<int>>& adjLists)
{
    if (node == end && spaceRemained == 0)
    {
        numOfPaths++;
        return;
    }

    visited[node] = true;
    for (auto& next : adjLists[node])
    {
        if (!visited[next])
            dfs(next, spaceRemained - 1, end, numOfPaths, visited, adjLists);
    }
    visited[node] = false;
}

int uniquePathsIII(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int N = m * n;

    // Build the graph
    vector<vector<int>> adjLists(N, vector<int>());
    int start, end, spaceRemained = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                start = i * n + j;
            if (grid[i][j] == 2)
                end = i * n + j;

            if (grid[i][j] != -1)
            {
                spaceRemained++;
                if (i > 0 && grid[i - 1][j] != -1)
                    adjLists[i * n + j].push_back((i-1) * n + j);
                if (j > 0 && grid[i][j - 1] != -1)
                    adjLists[i * n + j].push_back(i * n + (j-1));
                if (j < n - 1 && grid[i][j + 1] != -1)
                    adjLists[i * n + j].push_back(i * n + (j+1));
                if (i < m - 1 && grid[i + 1][j] != -1)
                    adjLists[i * n + j].push_back((i+1) * n + j);
            }
        }
    }

    // Search paths
    int output = 0;
    vector<bool> visited(N, false);
    dfs(start, spaceRemained - 1, end, output, visited, adjLists);

    return output;
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
    cout << uniquePathsIII(grid) << endl;

    return 0;
}
