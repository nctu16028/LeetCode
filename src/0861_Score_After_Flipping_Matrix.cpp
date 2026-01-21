#include <iostream>
#include <vector>
using namespace std;

int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int sum = 0;
    vector<int> colCount(n, 0);

    // Try flipping each row
    for (int i = 0; i < m; i++) {
        int row = 0, row_complement = 0;
        for (int j = 0; j < n; j++) {
            row = (row << 1) + grid[i][j];
            row_complement = (row_complement << 1) + (1 - grid[i][j]);
        }

        if (row > row_complement) {
            sum += row;
            for (int j = 0; j < n; j++)
                colCount[j] += grid[i][j];
        }
        else {
            sum += row_complement;
            for (int j = 0; j < n; j++)
                colCount[j] += (1 - grid[i][j]);
        }
    }

    // Try flipping each column
    for (int j = 0; j < n; j++) {
        if (m - colCount[j] > colCount[j]) {
            sum += ((m - colCount[j] - colCount[j]) << (n - 1 - j));
        }
    }

    return sum;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << matrixScore(grid) << endl;

    return 0;
}