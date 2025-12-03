#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size();
    int n = img[0].size();

    vector<vector<int>> output(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 1, sum = img[i][j];
            if (i > 0 && j > 0) {
                count++;
                sum += img[i - 1][j - 1];
            }
            if (i > 0) {
                count++;
                sum += img[i - 1][j];
            }
            if (i > 0 && j < n - 1) {
                count++;
                sum += img[i - 1][j + 1];
            }
            if (j > 0) {
                count++;
                sum += img[i][j - 1];
            }
            if (j < n - 1) {
                count++;
                sum += img[i][j + 1];
            }
            if (i < m - 1 && j > 0) {
                count++;
                sum += img[i + 1][j - 1];
            }
            if (i < m - 1) {
                count++;
                sum += img[i + 1][j];
            }
            if (i < m - 1 && j < n - 1) {
                count++;
                sum += img[i + 1][j + 1];
            }
            output[i][j] = sum / count;
        }
    }

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> img(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> img[i][j];

    vector<vector<int>> ans = imageSmoother(img);
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
