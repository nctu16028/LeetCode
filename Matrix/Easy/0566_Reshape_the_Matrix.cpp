#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
{
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c)
        return mat;

    vector<vector<int>> output(r, vector<int>(c));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i * n + j;
            int idx_r = idx / c;
            int idx_c = idx % c;
            output[idx_r][idx_c] = mat[i][j];
        }
    }

    return output;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m);
    for (int i = 0; i < m; i++)
    {
        mat[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    int r, c;
    cin >> r >> c;

    vector<vector<int>> ans = matrixReshape(mat, r, c);
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
