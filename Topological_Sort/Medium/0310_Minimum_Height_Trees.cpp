#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
{
    /* Key idea:
     *  We peel the leaves (nodes whose degree is 1) of the tree level-by-level,
     *  and finally the remaining one or two nodes are the root of MHT.
     */

    // Build the adjacency lists and count the degree of each node
    vector<vector<int>> adjLists(n, vector<int>());
    vector<int> degreeOf(n, 0);
    for (auto& edge : edges)
    {
        adjLists[edge[0]].push_back(edge[1]);
        adjLists[edge[1]].push_back(edge[0]);
        degreeOf[edge[0]]++;
        degreeOf[edge[1]]++;
    }

    // Set the leaves as the starter of the search
    queue<int> toVisit;
    for (int i = 0; i < n; i++)
    {
        if (degreeOf[i] <= 1)
            toVisit.push(i);
    }

    // Start reversed BFS (from leaves to center)
    vector<int> output;     // store the processed leaf in each level
    while (!toVisit.empty())
    {
        output.clear();     // remove the leaves in the previous level
        int levelSize = toVisit.size();
        for (int i = 0; i < levelSize; i++)
        {
            int u = toVisit.front();
            toVisit.pop();

            for (auto& v : adjLists[u])
            {
                if (degreeOf[v] > 0)
                {
                    // Peel one leaf u from node v
                    degreeOf[u]--;
                    degreeOf[v]--;
                    if (degreeOf[v] == 1)
                        toVisit.push(v);
                }
            }

            output.push_back(u);
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];

    vector<int> ans = findMinHeightTrees(n, edges);
    cout << "[" << ans[0];
    if (ans.size() > 1)
        cout << ", " << ans[1];
    cout << "]" << endl;

    return 0;
}
