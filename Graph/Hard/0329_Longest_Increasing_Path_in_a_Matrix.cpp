#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int nodeID, vector<int>& topoOrder, vector<bool>& isSearched, const vector<vector<int>>& adjLists)
{
    isSearched[nodeID] = true;

    for (auto& next : adjLists[nodeID])
    {
        if (!isSearched[next])
            dfs(next, topoOrder, isSearched, adjLists);
    }

    topoOrder.push_back(nodeID);
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // Build adjancency lists according to the moving rules
    vector<vector<int>> adjLists(m * n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                if (matrix[i][j] < matrix[i-1][j])
                    adjLists[i * n + j].push_back((i-1) * n + j);
                else if (matrix[i][j] > matrix[i-1][j])
                    adjLists[(i-1) * n + j].push_back(i * n + j);
            }
            if (j > 0)
            {
                if (matrix[i][j] < matrix[i][j-1])
                    adjLists[i * n + j].push_back(i * n + (j-1));
                else if (matrix[i][j] > matrix[i][j-1])
                    adjLists[i * n + (j-1)].push_back(i * n + j);
            }
        }
    }

    // Perform topological sorting on the cells by one DFS
    vector<int> topoOrder;
    vector<bool> isSearched(m * n, false);
    for (int u = 0; u < m * n; u++)
    {
        if (!isSearched[u])
            dfs(u, topoOrder, isSearched, adjLists);
    }
    reverse(topoOrder.begin(), topoOrder.end());

    // Perform dynamic programming in the topological order to find the longest path
    vector<int> dpTable(m * n, 1);  // dpTable[i] is the length of the longest path ending at cell i
    int output = 1;
    for (auto& u : topoOrder)
    {
        for (auto& v : adjLists[u])
        {
            if (dpTable[u] + 1 > dpTable[v])
            {
                dpTable[v] = dpTable[u] + 1;
                if (dpTable[v] > output)
                    output = dpTable[v];
            }
        }
    }

    return output;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << longestIncreasingPath(matrix) << endl;

    return 0;
}
