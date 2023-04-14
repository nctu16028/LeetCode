#include <iostream>
#include <vector>
using namespace std;

void dfs1(int root, int parent, vector<int>& sumOfDistancesOfNode, vector<int>& descendantSizeOfNode, const vector<vector<int>>& adjList)
{
    for (auto& neighbor : adjList[root])
    {
        if (neighbor != parent)
        {
            dfs1(neighbor, root, sumOfDistancesOfNode, descendantSizeOfNode, adjList);
            descendantSizeOfNode[root] += descendantSizeOfNode[neighbor];
            sumOfDistancesOfNode[root] += (sumOfDistancesOfNode[neighbor] + descendantSizeOfNode[neighbor]);
        }
    }
}

void dfs2(int root, int parent, vector<int>& sumOfDistancesOfNode, const vector<int>& descendantSizeOfNode, const vector<vector<int>>& adjList)
{
    int n = adjList.size();
    for (auto& neighbor : adjList[root])
    {
        if (neighbor != parent)
        {
            // When changing from "rooted at root" to "rooted at neighbor", there are (descendantSizeOfNode[neighbor]) more nodes that can
            // be reached without passing by the edge (root, neighbor), but there are also (n - descendantSizeOfNode[neighbor]) more nodes
            // that must be reached with passing by the edge (neighbor, root).
            sumOfDistancesOfNode[neighbor] = sumOfDistancesOfNode[root] - descendantSizeOfNode[neighbor] + (n - descendantSizeOfNode[neighbor]);
            dfs2(neighbor, root, sumOfDistancesOfNode, descendantSizeOfNode, adjList);
        }
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
{
    // Convert the edge set to adjacency lists
    vector<vector<int>> adjList(n, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> sumOfDistancesOfNode(n, 0);
    vector<int> descendantSizeOfNode(n, 1);

    // First DFS: With 0 as the root, compute the values of descendantSizeOfNode as well as sumOfDistancesOfNode[0],
    //            where descendantSizeOfNode[i] is the number of nodes that you can go from i to without passing by
    //            the edge {i, parent(i)}
    dfs1(0, -1, sumOfDistancesOfNode, descendantSizeOfNode, adjList);

    // Second DFS: With descendantSizeOfNode in hand, calculate the other values of sumOfDistancesOfNode.
    dfs2(0, -1, sumOfDistancesOfNode, descendantSizeOfNode, adjList);

    return sumOfDistancesOfNode;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<int> ans = sumOfDistancesInTree(n, edges);
    cout << "[" << ans[0];
    for (int i = 1; i < n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
