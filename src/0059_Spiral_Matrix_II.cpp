#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int upwardBound = 0;
    int downwardBound = m;
    int leftBound = -1;
    int rightBound = n;
    vector<int> output;

    int i = 0, j = 0;
    int direction = 0;      // 0: >; 1: v; 2: <; 3: ^
    while (output.size() < m * n) {
        output.push_back(matrix[i][j]);
        if (direction == 0) {
            if (j == rightBound - 1) {
                direction = 1;
                rightBound--;
                i++;
            }
            else
                j++;
        }
        else if (direction == 1) {
            if (i == downwardBound - 1) {
                direction = 2;
                downwardBound--;
                j--;
            }
            else
                i++;
        }
        else if (direction == 2) {
            if (j == leftBound + 1) {
                direction = 3;
                leftBound++;
                i--;
            }
            else
                j--;
        }
        else {
            if (i == upwardBound + 1) {
                direction = 0;
                upwardBound++;
                j++;
            }
            else
                i--;
        }
    }

    return output;
}

vector<vector<int>> generateMatrix(int n) {
    int target = n * n;
    int upwardBound = 0;
    int downwardBound = n;
    int leftBound = -1;
    int rightBound = n;
    vector<vector<int>> output(n, vector<int>(n));

    int i = 0, j = 0, val = 1;
    int direction = 0;      // 0: >; 1: v; 2: <; 3: ^
    while (val <= target) {
        output[i][j] = val++;
        if (direction == 0) {
            if (j == rightBound - 1) {
                direction = 1;
                rightBound--;
                i++;
            }
            else
                j++;
        }
        else if (direction == 1) {
            if (i == downwardBound - 1) {
                direction = 2;
                downwardBound--;
                j--;
            }
            else
                i++;
        }
        else if (direction == 2) {
            if (j == leftBound + 1) {
                direction = 3;
                leftBound++;
                i--;
            }
            else
                j--;
        }
        else {
            if (i == upwardBound + 1) {
                direction = 0;
                upwardBound++;
                j++;
            }
            else
                i--;
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans = generateMatrix(n);

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
