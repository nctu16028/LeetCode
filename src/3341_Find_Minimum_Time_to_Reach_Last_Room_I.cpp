#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size();
    int n = moveTime[0].size();

    // Initialization of Dijkstra algorithm
    vector<vector<int>> costFromStart(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> relaxed(m, vector<bool>(n, false));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toRelax;

    // Set up the starting grid
    costFromStart[0][0] = 0;
    toRelax.push(make_pair(costFromStart[0][0], 0 * n + 0));

    // Relaxation
    while (!toRelax.empty()) {
        int u = toRelax.top().second;
        toRelax.pop();

        int i = u / n;
        int j = u % n;
        if (i == m - 1 && j == n - 1)
            break;
        else if (relaxed[i][j])
            continue;
        else
            relaxed[i][j] = true;

        // Find all the neighbors of the current grid
        if (i > 0 && !relaxed[i - 1][j] && max(costFromStart[i][j], moveTime[i - 1][j]) + 1 < costFromStart[i - 1][j]) {
            costFromStart[i - 1][j] = max(costFromStart[i][j], moveTime[i - 1][j]) + 1;
            toRelax.push(make_pair(costFromStart[i - 1][j], (i - 1) * n + j));
        }
        if (i < m - 1 && !relaxed[i + 1][j] && max(costFromStart[i][j], moveTime[i + 1][j]) + 1 < costFromStart[i + 1][j]) {
            costFromStart[i + 1][j] = max(costFromStart[i][j], moveTime[i + 1][j]) + 1;
            toRelax.push(make_pair(costFromStart[i + 1][j], (i + 1) * n + j));
        }
        if (j > 0 && !relaxed[i][j - 1] && max(costFromStart[i][j], moveTime[i][j - 1]) + 1 < costFromStart[i][j - 1]) {
            costFromStart[i][j - 1] = max(costFromStart[i][j], moveTime[i][j - 1]) + 1;
            toRelax.push(make_pair(costFromStart[i][j - 1], i * n + (j - 1)));
        }
        if (j < n - 1 && !relaxed[i][j + 1] && max(costFromStart[i][j], moveTime[i][j + 1]) + 1 < costFromStart[i][j + 1]) {
            costFromStart[i][j + 1] = max(costFromStart[i][j], moveTime[i][j + 1]) + 1;
            toRelax.push(make_pair(costFromStart[i][j + 1], i * n + (j + 1)));
        }
    }

    return costFromStart[m - 1][n - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> moveTime(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> moveTime[i][j];
    }
    cout << minTimeToReach(moveTime) << endl;

    return 0;
}
