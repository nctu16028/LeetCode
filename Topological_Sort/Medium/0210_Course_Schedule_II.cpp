#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int nodeID, vector<int>& topoOrder, vector<bool>& isSearched, vector<bool>& isAncestor, const vector<vector<int>>& adjLists)
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

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    // Build the graph
    vector<vector<int>> adjLists(numCourses, vector<int>());
    for (auto& arc : prerequisites)
        adjLists[arc[1]].push_back(arc[0]);

    // Perform topological sorting by DFS
    vector<int> topoOrder;
    vector<bool> isSearched(numCourses, false);
    vector<bool> isAncestor(numCourses, false);
    bool flag = true;
    for (int u = 0; u < numCourses; u++)
    {
        if (!isSearched[u])
            flag = dfs(u, topoOrder, isSearched, isAncestor, adjLists);
        if (!flag)
            break;
    }

    if (!flag)
        topoOrder.clear();
    else
        reverse(topoOrder.begin(), topoOrder.end());

    return topoOrder;
}

int main()
{
    int numCourses, m;
    cin >> numCourses >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        cin >> prerequisites[i][0] >> prerequisites[i][1];

    vector<int> ans = findOrder(numCourses, prerequisites);
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
