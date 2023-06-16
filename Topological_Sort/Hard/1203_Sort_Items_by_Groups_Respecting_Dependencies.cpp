#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool dfs(int nodeID, vector<int>& topoOrder, vector<bool>& isSearched, vector<bool>& isAncestor, const vector<set<int>>& adjLists)
{
    bool flag = true;
    isSearched[nodeID] = true;
    isAncestor[nodeID] = true;
    for (auto& next : adjLists[nodeID])
    {
        if (isAncestor[next])   // a cycle exists
            flag = false;
        else if (!isSearched[next])
            flag = dfs(next, topoOrder, isSearched, isAncestor, adjLists);

        if (!flag) 
            return false;
    }
    isAncestor[nodeID] = false;
    topoOrder.push_back(nodeID);

    return flag;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
{
    // Build the graph
    int numVertices = n + 2 * m;    // 0~(n-1): nodes; n~(n+m-1): group wrapper heads; (n+m)~(n+2m-1): group wrapper tails
    vector<set<int>> adjLists(numVertices, set<int>());
    for (int i = 0; i < n; i++)
    {
        // Wrap the groups
        if (group[i] != -1)
        {
            adjLists[n + group[i]].insert(i);       // connect group head
            adjLists[i].insert(n + m + group[i]);   // connect group tail
        }

        // Handle the dependencies
        for (auto& prev : beforeItems[i])
        {
            if (group[prev] == group[i])
                adjLists[prev].insert(i);
            else
            {
                if (group[prev] == -1)
                    adjLists[prev].insert(n + group[i]);                    // prev -> i's group head
                else if (group[i] == -1)
                    adjLists[n + m + group[prev]].insert(i);                // prev's group tail -> i
                else
                    adjLists[n + m + group[prev]].insert(n + group[i]);     // prev's group tail -> i's group head
            }
        }
    }

    // Perform topological sorting by DFS (group heads need to go first)
    vector<int> reversedTopoOrder;
    vector<bool> isSearched(numVertices, false);
    vector<bool> isAncestor(numVertices, false);
    bool flag = true;
    for (int u = n; u < n + m; u++)
    {
        if (!flag)
            break;
        if (!isSearched[u])
            flag = dfs(u, reversedTopoOrder, isSearched, isAncestor, adjLists);
    }
    for (int u = 0; u < n; u++)
    {
        if (!flag)
            break;
        if (!isSearched[u])
            flag = dfs(u, reversedTopoOrder, isSearched, isAncestor, adjLists);
    }

    vector<int> output;
    if (flag)
    {
        for (int i = reversedTopoOrder.size() - 1; i >= 0; i--)
        {
            if (reversedTopoOrder[i] < n)
                output.push_back(reversedTopoOrder[i]);
        }
    }

    return output;
}

int main()
{
    int n = 8, m = 2;
    vector<int> group({-1, -1, 1, 0, 0, 1, 0, -1});
    //vector<vector<int>> beforeItems({{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}});
    vector<vector<int>> beforeItems({{}, {6}, {5}, {6}, {3}, {}, {4}, {}});

    vector<int> ans = sortItems(n, m, group, beforeItems);
    cout << "[";
    if (!ans.empty())
    {
        cout << ans[0];
        for (int i = 1; i < n; i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    return 0;
}
