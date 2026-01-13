#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();
    int output = 0;
    for (int i = 1; i < n; i++) {
        int x_diff = abs(points[i][0] - points[i - 1][0]);
        int y_diff = abs(points[i][1] - points[i - 1][1]);
        output += max(x_diff, y_diff);
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];
    cout << minTimeToVisitAllPoints(points) << endl;

    return 0;
}