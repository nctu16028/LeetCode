#include <iostream>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Initialize all land blocks as isolated vertices
    vector<vector<int>> cpnRep(m, vector<int>(n, -1));
    int output = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                cpnRep[i][j] = i * n + j;
                output++;
            }
        }
    }

    // Traverse all horizontal '1'-'1' edges
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j - 1] == '1' && grid[i][j] == '1') {
                // Tag grid[i][j - 1] and grid[i][j] as the same component
                int repU = cpnRep[i][j - 1];
                while (repU != cpnRep[repU / n][repU % n])
                    repU = cpnRep[repU / n][repU % n];      // trace to the root representative of u
                int repV = cpnRep[i][j];
                while (repV != cpnRep[repV / n][repV % n])
                    repV = cpnRep[repV / n][repV % n];      // trace to the root representative of v
                if (repU != repV) {
                    cpnRep[max(repU, repV) / n][max(repU, repV) % n] = min(repU, repV);
                    output--;
                }
            }
        }
    }

    // Traverse all vertical '1'-'1' edges
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < m; i++) {
            if (grid[i - 1][j] == '1' && grid[i][j] == '1') {
                // Tag grid[i - 1][j] and grid[i][j] as the same component
                int repU = cpnRep[i - 1][j];
                while (repU != cpnRep[repU / n][repU % n])
                    repU = cpnRep[repU / n][repU % n];      // trace to the root representative of u
                int repV = cpnRep[i][j];
                while (repV != cpnRep[repV / n][repV % n])
                    repV = cpnRep[repV / n][repV % n];      // trace to the root representative of v
                if (repU != repV) {
                    cpnRep[max(repU, repV) / n][max(repU, repV) % n] = min(repU, repV);
                    output--;
                }
            }
        }
    }

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << numIslands(grid) << endl;

    return 0;
}
