#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<vector<int>>& grid)
{
    // Build the graph
    int row = grid.size(), col = grid[0].size();
    int n = row * col;
    vector<vector<pair<int, bool>>> adjLists(n, vector<pair<int, bool>>());
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i > 0)          // assign upward weight to 0 if grid[i][j] is "^" or 1 otherwise
                adjLists[i * col + j].push_back(make_pair((i-1) * col + j, (grid[i][j] != 4)));
            if (i < row - 1)    // assign downward weight to 0 if grid[i][j] is "v" or 1 otherwise
                adjLists[i * col + j].push_back(make_pair((i+1) * col + j, (grid[i][j] != 3)));
            if (j > 0)          // assign leftward weight to 0 if grid[i][j] is "<-" or 1 otherwise
                adjLists[i * col + j].push_back(make_pair(i * col + (j-1), (grid[i][j] != 2)));
            if (j < col - 1)    // assign rightward weight to 0 if grid[i][j] is "->" or 1 otherwise
                adjLists[i * col + j].push_back(make_pair(i * col + (j+1), (grid[i][j] != 1)));
        }
    }

    // Initialization of Dijkstra algorithm
    vector<int> distFrom0(n, INT_MAX);
    vector<bool> relaxed(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toRelax;

    // Determine the starting vertex
    distFrom0[0] = 0;
    toRelax.push(make_pair(distFrom0[0], 0));

    // Relax all the vertices that can be reached from 0
    while (!toRelax.empty())
    {
        int u = toRelax.top().second;
        toRelax.pop();
        if (relaxed[u])
            continue;
        relaxed[u] = true;
        if (u == n - 1)
            break;

        // Find all the neighbors of the current vertex
        for (auto& arc : adjLists[u])
        {
            int v = arc.first;
            int w = arc.second;
            if (!relaxed[v] && distFrom0[u] + w < distFrom0[v])
            {
                distFrom0[v] = distFrom0[u] + w;
                toRelax.push(make_pair(distFrom0[v], v));
            }
        }
    }

    return distFrom0[n - 1];
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
    cout << minCost(grid) << endl;

    return 0;
}
