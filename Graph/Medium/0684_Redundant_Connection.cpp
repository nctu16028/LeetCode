#include <iostream>
#include <vector>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
    int n = edges.size();
    vector<int> cpnRep(n, -1);      // cpnRep[i] == -1 means i is an isolated vertex
    for (auto& rel : edges)
    {
        int u = rel[0] - 1;
        int v = rel[1] - 1;

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

            if (repU == repV)   // the edge trying to connect the vertices from the same component is the redundant one
                return rel;
            else
                cpnRep[max(repU, repV)] = min(repU, repV);
        }
    }

    return edges[n - 1];    // this line won't be reached normally
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<int> ans = findRedundantConnection(edges);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
