#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n = image.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j <= k; j++, k--) {
            if (j != k) {
                swap(image[i][j], image[i][k]);
                image[i][j] = 1 - image[i][j];
                image[i][k] = 1 - image[i][k];
            }
            else
                image[i][j] = 1 - image[i][j];
        }
    }

    return image;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> image[i][j];
    }

    vector<vector<int>> ans = flipAndInvertImage(image);
    if (n == 1)
        cout << "[[" << ans[0][0] << "]]" << endl;
    else {
        cout << "[[" << ans[0][0];
        for (int j = 1; j < n; j++)
            cout << ", " << ans[0][j];
        for (int i = 1; i < n; i++) {
            cout << "], [" << ans[i][0];
            for (int j = 1; j < n; j++)
                cout << ", " << ans[i][j];
        }
        cout << "]]" << endl;
    }

    return 0;
}