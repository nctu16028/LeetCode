#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> label(n, 0);    // use 1 and -1 to represent two sets

    queue<int> toVisit;
    for (int i = 0; i < n; i++)
    {
        if (label[i] != 0)
            continue;

        // Perform alternating-BFS on the component starting from vertex i
        label[i] = 1;
        toVisit.push(i);
        while (!toVisit.empty())
        {
            int u = toVisit.front();
            toVisit.pop();
            for (auto& v : graph[u])
            {
                if (label[v] == label[u])
                    return false;
                else if (label[v] == 0)
                {
                    label[v] = -label[u];
                    toVisit.push(v);
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> graph(4);
    graph[0] = vector<int>({1, 2, 3});
    graph[1] = vector<int>({0, 2});
    graph[2] = vector<int>({0, 1, 3});
    graph[3] = vector<int>({0, 2});
    cout << (isBipartite(graph) ? "true" : "false") << endl;

    return 0;
}
