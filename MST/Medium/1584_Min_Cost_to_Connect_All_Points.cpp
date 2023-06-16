#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points)
{
    // Build the graph
    int n = points.size();
    vector<vector<pair<int, int>>> adjLists(n, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            adjLists[i].push_back(make_pair(j, dist));
            adjLists[j].push_back(make_pair(i, dist));
        }
    }

    // Initialization of Prim algorithm
    vector<int> minWeightTo(n, INT_MAX);
    vector<bool> relaxed(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toRelax;

    // Determine the starting vertex
    minWeightTo[0] = 0;
    toRelax.push(make_pair(minWeightTo[0], 0));

    // Relax all the vertices that can be reached from 0
    int output = 0;
    while (!toRelax.empty())
    {
        int u = toRelax.top().second;
        toRelax.pop();
        if (relaxed[u])
            continue;
        relaxed[u] = true;
        output += minWeightTo[u];

        // Find all the neighbors of the current vertex
        for (auto& arc : adjLists[u])
        {
            int v = arc.first;
            int w = arc.second;
            if (!relaxed[v] && w < minWeightTo[v])
            {
                minWeightTo[v] = w;
                toRelax.push(make_pair(minWeightTo[v], v));
            }
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];
    cout << minCostConnectPoints(points) << endl;

    return 0;
}
