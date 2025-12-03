#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<vector<int>> output(numRows);
    output[0] = vector<int>(1, 1);
    if (numRows > 1) {
        output[1] = vector<int>(2, 1);
        for (int i = 2; i < numRows; i++) {
            output[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++)
                output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
        }
    }

    return output[rowIndex];
}

int main() {
    int rowIndex;
    cin >> rowIndex;

    vector<int> ans = getRow(rowIndex);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
