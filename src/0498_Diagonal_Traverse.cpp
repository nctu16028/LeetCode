#include <iostream>
#include <vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> output(m * n);
    int size = 0;
    for (int d = 0; d < m + n - 1; d++) {
        if (d % 2) {
            for (int i = 0; i <= d; i++) {
                int j = d - i;
                if (i < m && j < n) {
                    output[size] = mat[i][j];
                    size++;
                }
            }
        }
        else {
            for (int j = 0; j <= d; j++) {
                int i = d - j;
                if (i < m && j < n) {
                    output[size] = mat[i][j];
                    size++;
                }
            }
        }
    }

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    vector<int> ans = findDiagonalOrder(mat);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
