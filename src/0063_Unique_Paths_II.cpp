#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> count(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                count[i][j] = (obstacleGrid[i][j] == 1) ? 0 : 1;
            else if (i == 0)
                count[i][j] = (obstacleGrid[i][j] == 1) ? 0 : count[i][j - 1];
            else if (j == 0)
                count[i][j] = (obstacleGrid[i][j] == 1) ? 0 : count[i - 1][j];
            else
                count[i][j] = (obstacleGrid[i][j] == 1) ? 0 : (count[i - 1][j] + count[i][j - 1]);
        }
    }

    return count[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> obstacleGrid[i][j];
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
