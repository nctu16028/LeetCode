#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> output(n, vector<int>(m));
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
            output[j][i] = matrix[i][j];

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    vector<vector<int>> ans = transpose(matrix);
    cout << "[[" << ans[0][0];
    for (int j = 1; j < ans[0].size(); j++)
        cout << ", " << ans[0][j];
    cout << "]";
    for (int i = 1; i < ans.size(); i++) {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
