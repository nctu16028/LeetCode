#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class DisjointSets
{
public:
    DisjointSets(int n)
    {
        cpnRep.resize(n, -1);
    }

    bool merge(int u, int v)
    {
        if (cpnRep[u] == -1 && cpnRep[v] == -1)
        {
            cpnRep[u] = min(u, v);
            cpnRep[v] = cpnRep[u];
        }
        else if (cpnRep[u] == -1)
            cpnRep[u] = cpnRep[v];
        else if (cpnRep[v] == -1)
            cpnRep[v] = cpnRep[u];
        else
        {
            int repU = cpnRep[u];
            while (repU != cpnRep[repU]) repU = cpnRep[repU];   // trace to the root representative of u
            int repV = cpnRep[v];
            while (repV != cpnRep[repV]) repV = cpnRep[repV];   // trace to the root representative of v
            if (repU == repV)
                return false;   // merging failed because u and v are already in the same component
            cpnRep[max(repU, repV)] = min(repU, repV);
        }
        return true;            // merging successed
    }

private:
    vector<int> cpnRep;
};

int restrictedKruskal(int n, const vector<vector<int>>& edges, const vector<pair<int, int>>& sortedEdges, int accepted, int rejected)
{
    int mstCost = 0, numComponent = n;
    DisjointSets djs(n);
    if (accepted != -1)
    {
        djs.merge(edges[accepted][0], edges[accepted][1]);
        numComponent--;
        mstCost += edges[accepted][2];
        rejected = accepted;    // avoid it being picked again
    }

    for (auto& e : sortedEdges)
    {
        if (numComponent == 1)
            break;

        int idx = e.second;
        if (idx == rejected)    // cannot use this edge
            continue;

        if (djs.merge(edges[idx][0], edges[idx][1]))
        {
            numComponent--;
            mstCost += edges[idx][2];
        }
    }

    return (numComponent > 1) ? INT_MAX : mstCost;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
{
    // Sort the edges
    int m = edges.size();
    vector<pair<int, int>> sortedEdges(m);
    for (int i = 0; i < m; i++)
        sortedEdges[i] = make_pair(edges[i][2], i);
    sort(sortedEdges.begin(), sortedEdges.end());

    // Find a minimum spanning tree using Kruskal algorithm
    int mstCost = 0, numComponent = n;
    set<int> mstEdges;          // indices of edges that are used in this MST
    DisjointSets djs(n);
    for (auto& e : sortedEdges)
    {
        if (numComponent == 1)
            break;
        int idx = e.second;
        if (djs.merge(edges[idx][0], edges[idx][1]))
        {
            numComponent--;
            mstCost += edges[idx][2];
            mstEdges.insert(idx);
        }
    }

    // Find critical and pseudo-critical edges
    vector<vector<int>> output(2, vector<int>());
    for (int i = 0; i < m; i++)
    {
        if (mstEdges.find(i) == mstEdges.end())
        {
            if (restrictedKruskal(n, edges, sortedEdges, i, -1) == mstCost)
                output[1].push_back(i);     // pseudo-critical
        }
        else
        {
            if (restrictedKruskal(n, edges, sortedEdges, -1, i) > mstCost)
                output[0].push_back(i);     // critical
            else
                output[1].push_back(i);     // pseudo-critical
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

    vector<vector<int>> ans = findCriticalAndPseudoCriticalEdges(n, edges);
    cout << "[[";
    if (!ans[0].empty())
    {
        cout << ans[0][0];
        for (int j = 1; j < ans[0].size(); j++)
            cout << ", " << ans[0][j];
    }
    cout << "], [";
    if (!ans[1].empty())
    {
        cout << ans[1][0];
        for (int j = 1; j < ans[1].size(); j++)
            cout << ", " << ans[1][j];
    }
    cout << "]]" << endl;

    return 0;
}
