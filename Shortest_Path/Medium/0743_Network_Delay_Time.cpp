#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    // Build the graph
    vector<vector<pair<int, int>>> adjLists(n, vector<pair<int, int>>());
    for (auto& arc : times)     // each arc is {s, e, w}, where s and e are 1-indexed
        adjLists[arc[0] - 1].push_back(make_pair(arc[1] - 1, arc[2]));

    // Initialization of Dijkstra algorithm
    vector<int> distFromK(n, INT_MAX);
    vector<bool> relaxed(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toRelax;

    // Determine the starting vertex
    distFromK[k - 1] = 0;
    toRelax.push(make_pair(distFromK[k - 1], k - 1));

    // Relax all the vertices that can be reached from k
    int output = 0, count = 0;
    while (!toRelax.empty())
    {
        int u = toRelax.top().second;
        toRelax.pop();
        if (relaxed[u])
            continue;
        relaxed[u] = true;
        output = max(output, distFromK[u]);
        count++;

        // Find all the neighbors of the current vertex
        for (auto& arc : adjLists[u])
        {
            int v = arc.first;
            int w = arc.second;
            if (!relaxed[v] && distFromK[u] + w < distFromK[v])
            {
                distFromK[v] = distFromK[u] + w;
                toRelax.push(make_pair(distFromK[v], v));
            }
        }
    }

    return (count < n) ? -1 : output;
}

int main()
{
    int m;
    cin >> m;

    vector<vector<int>> times(m, vector<int>(3));
    for (int i = 0; i < m; i++)
        cin >> times[i][0] >> times[i][1] >> times[i][2];

    int n, k;
    cin >> n >> k;
    cout << networkDelayTime(times, n, k) << endl;

    return 0;
}
