#include <iostream>
#include <vector>
using namespace std;

bool dfs(int nodeID, vector<bool>& isSearched, vector<bool>& isAncestor, const vector<vector<int>>& adjLists) {
    bool flag = true;
    isSearched[nodeID] = true;
    isAncestor[nodeID] = true;
    for (auto& next : adjLists[nodeID]) {
        if (isAncestor[next])   // a cycle exists
            flag = false;
        else if (!isSearched[next])
            flag = dfs(next, isSearched, isAncestor, adjLists);

        if (!flag)
            return false;
    }
    isAncestor[nodeID] = false;

    return flag;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Build the graph
    vector<vector<int>> adjLists(numCourses, vector<int>());
    for (auto& arc : prerequisites)
        adjLists[arc[1]].push_back(arc[0]);

    // Perform DFS
    vector<bool> isSearched(numCourses, false);
    vector<bool> isAncestor(numCourses, false);
    bool flag = true;
    for (int u = 0; u < numCourses; u++) {
        if (!isSearched[u])
            flag = dfs(u, isSearched, isAncestor, adjLists);
        if (!flag)
            break;
    }

    return flag;
}

int main() {
    int numCourses, m;
    cin >> numCourses >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;

    return 0;
}
