#include <iostream>
#include <vector>
using namespace std;

void buildPath(vector<vector<int>>& paths, vector<int>& currPath, int node, const vector<vector<int>>& graph)
{
    if (node == graph.size() - 1)
    {
        paths.push_back(currPath);
        return;
    }

    for (auto& next : graph[node])
    {
        currPath.push_back(next);
        buildPath(paths, currPath, next, graph);
        currPath.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    vector<vector<int>> output;
    vector<int> path(1, 0);
    buildPath(output, path, 0, graph);

    return output;
}

int main()
{
    vector<vector<int>> graph({{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}});
    vector<vector<int>> ans = allPathsSourceTarget(graph);
    cout << "[[" << ans[0][0];
    for (int j = 1; j < ans[0].size(); j++)
        cout << ", " << ans[0][j];
    cout << "]";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
