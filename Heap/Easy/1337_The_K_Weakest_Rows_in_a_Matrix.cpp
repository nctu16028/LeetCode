#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     // min-heap of pair<int, int>
    for (int i = 0; i < mat.size(); i++)
    {
        vector<int>::iterator first_zero = lower_bound(mat[i].begin(), mat[i].end(), 0, greater<int>());
        int powerOfRow = first_zero - mat[i].begin();
        pq.push(make_pair(powerOfRow, i));
    }

    vector<int> output(k);
    for (int i = 0; i < k; i++)
    {
        output[i] = pq.top().second;
        pq.pop();
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

    int k;
    cin >> k;

    vector<int> ans = kWeakestRows(mat, k);
    cout << "[" << ans[0];
    for (int i = 1; i < k; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
