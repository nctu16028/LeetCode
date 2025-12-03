#include <iostream>
#include <vector>
using namespace std;

pair<int, int> partition(vector<vector<int>>& a, int head, int tail) {
    // The tail is chosen as the pivot
    int k = head - 1;                       // [head, k] is the interval whose elements are smaller than pivot
    int i = head - 1;                       // [k + 1, i] is the interval whose elements are equal to pivot
    for (int j = head; j < tail; j++) {     // [i + 1, j - 1] is the interval whose elements are larger than pivot
        if (a[j][0] * a[j][0] + a[j][1] * a[j][1] <= a[tail][0] * a[tail][0] + a[tail][1] * a[tail][1]) {
            i++;
            swap(a[i], a[j]);
            if (a[i][0] * a[i][0] + a[i][1] * a[i][1] < a[tail][0] * a[tail][0] + a[tail][1] * a[tail][1]) {
                k++;
                swap(a[k], a[i]);
            }
        }
    }
    swap(a[i + 1], a[tail]);                // Move the pivot to the right place

    // Now the pivot is at i + 1
    return make_pair(k + 1, i + 1);
}

void quickselect(vector<vector<int>>& a, int head, int tail, int order) {
    pair<int, int> pivot = partition(a, head, tail);
    if (order < pivot.first)
        quickselect(a, head, pivot.first - 1, order);
    else if (order > pivot.second)
        quickselect(a, pivot.second + 1, tail, order);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n = points.size();
    quickselect(points, 0, n - 1, k - 1);
    vector<vector<int>> output(points.begin(), points.begin() + k);
    return output;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    int k;
    cin >> k;

    vector<vector<int>> ans = kClosest(points, k);
    cout << "[[" << ans[0][0] << ", " << ans[0][1] << "]";
    for (int i = 1; i < ans.size(); i++)
        cout << ", [" << ans[i][0] << ", " << ans[i][1] << "]";
    cout << "]" << endl;

    return 0;
}
