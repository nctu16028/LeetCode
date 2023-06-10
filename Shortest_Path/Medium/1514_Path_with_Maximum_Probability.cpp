#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <float.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    // Build the graph
    vector<vector<pair<int, double>>> adjLists(n, vector<pair<int, double>>());
    for (int i = 0; i < edges.size(); i++)
    {
        double weight = -log(succProb[i]);
        adjLists[edges[i][0]].push_back(make_pair(edges[i][1], weight));
        adjLists[edges[i][1]].push_back(make_pair(edges[i][0], weight));
    }

    // Initialization of Dijkstra algorithm
    vector<double> distFromStart(n, DBL_MAX);
    vector<bool> relaxed(n, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> toRelax;

    // Determine the starting vertex
    distFromStart[start] = 0;
    toRelax.push(make_pair(distFromStart[start], start));

    // Relax all the vertices that can be reached from start
    while (!toRelax.empty())
    {
        int u = toRelax.top().second;
        toRelax.pop();
        if (relaxed[u])
            continue;
        relaxed[u] = true;
        if (u == end)
            break;

        // Find all the neighbors of the current vertex
        for (auto& arc : adjLists[u])
        {
            int v = arc.first;
            double w = arc.second;
            if (!relaxed[v] && distFromStart[u] + w < distFromStart[v])
            {
                distFromStart[v] = distFromStart[u] + w;
                toRelax.push(make_pair(distFromStart[v], v));
            }
        }
    }

    return (distFromStart[end] == DBL_MAX) ? 0 : exp(-distFromStart[end]);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<double> succProb(m);
    for (int i = 0; i < m; i++)
        cin >> succProb[i];

    int start, end;
    cin >> start >> end;
    cout << maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}
