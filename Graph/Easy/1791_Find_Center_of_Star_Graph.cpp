#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges)
{
    // Since the star graph has only n-1 edges, the non-center nodes must be leaves (deg = 1).
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    else
        return edges[0][1];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
        cin >> edges[i][0] >> edges[i][1];
    cout << findCenter(edges) << endl;

    return 0;
}
