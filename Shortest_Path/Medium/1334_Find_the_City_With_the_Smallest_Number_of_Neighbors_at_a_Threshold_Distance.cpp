#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int dijkstraWithThreshold(int n, const vector<vector<pair<int, int>>>& adjLists, int distanceThreshold, int start)
{
    // Initialization of Dijkstra algorithm
    vector<int> distFromStart(n, INT_MAX);
    vector<bool> relaxed(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toRelax;

    // Determine the starting vertex
    distFromStart[start] = 0;
    toRelax.push(make_pair(distFromStart[start], start));

    // Relax all the vertices that can be reached from k within threshold
    int count = 0;
    while (!toRelax.empty())
    {
        if (toRelax.top().first > distanceThreshold)
            break;

        int u = toRelax.top().second;
        toRelax.pop();
        if (relaxed[u])
            continue;
        relaxed[u] = true;
        count++;

        // Find all the neighbors of the current vertex
        for (auto& arc : adjLists[u])
        {
            int v = arc.first;
            int w = arc.second;
            if (!relaxed[v] && distFromStart[u] + w < distFromStart[v])
            {
                distFromStart[v] = distFromStart[u] + w;
                toRelax.push(make_pair(distFromStart[v], v));
            }
        }
    }

    return count;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
    // Build the graph
    vector<vector<pair<int, int>>> adjLists(n, vector<pair<int, int>>());
    for (auto& edge : edges)     // each edge is {u, v, w}, where u and v are 0-indexed
    {
        adjLists[edge[0]].push_back(make_pair(edge[1], edge[2]));
        adjLists[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    // Perform Dijkstra algorithm for n times
    int output = 0, minNumReachable = n;
    for (int i = 0; i < n; i++)
    {
        int numReachable = dijkstraWithThreshold(n, adjLists, distanceThreshold, i);
        if (numReachable <= minNumReachable)
        {
            output = i;
            minNumReachable = numReachable;
        }
    }

    return output;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int distanceThreshold;
    cin >> distanceThreshold;
    cout << findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}
