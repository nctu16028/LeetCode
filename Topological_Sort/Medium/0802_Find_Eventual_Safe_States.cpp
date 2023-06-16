#include <iostream>
#include <vector>
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

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    // Perform topological sorting
    int n = graph.size();
    vector<int> reversedTopoOrder;
    vector<bool> isSearched(n, false);
    for (int u = 0; u < n; u++)
    {
        if (!isSearched[u])
            dfs(u, reversedTopoOrder, isSearched, graph);
    }

    // Find safe states in topological order
    vector<bool> isSafe(n, false);
    for (auto& state : reversedTopoOrder)
    {
        bool flag = true;
        for (auto& next : graph[state])
        {
            if (!isSafe[next])
            {
                flag = false;
                break;
            }
        }
        isSafe[state] = flag;
    }

    vector<int> output;
    for (int i = 0; i < n; i++)
    {
        if (isSafe[i])
            output.push_back(i);
    }

    return output;
}

int main()
{
    //vector<vector<int>> graph({{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}});
    vector<vector<int>> graph({{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}});
    vector<int> ans = eventualSafeNodes(graph);
    cout << "[";
    if (!ans.empty())
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    return 0;
}
