#include <iostream>
#include <vector>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    int n = coordinates.size();
    if (n <= 2)
        return true;

    int refVecX = coordinates[1][0] - coordinates[0][0];
    int refVecY = coordinates[1][1] - coordinates[0][1];
    for (int i = 2; i < n; i++) {
        int iVecX = coordinates[i][0] - coordinates[0][0];
        int iVecY = coordinates[i][1] - coordinates[0][1];
        if (refVecX * iVecY - refVecY * iVecX != 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> coordinates(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> coordinates[i][0] >> coordinates[i][1];
    cout << (checkStraightLine(coordinates) ? "true" : "false") << endl;

    return 0;
}
