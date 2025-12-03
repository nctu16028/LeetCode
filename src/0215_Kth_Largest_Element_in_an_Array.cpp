#include <iostream>
#include <vector>
using namespace std;

pair<int, int> partition(vector<int>& a, int head, int tail) {
    // The tail is chosen as the pivot
    int k = head - 1;                       // [head, k] is the interval whose elements are smaller than pivot
    int i = head - 1;                       // [k + 1, i] is the interval whose elements are equal to pivot
    for (int j = head; j < tail; j++) {     // [i + 1, j - 1] is the interval whose elements are larger than pivot
        if (a[j] <= a[tail]) {
            i++;
            swap(a[i], a[j]);
            if (a[i] < a[tail]) {
                k++;
                swap(a[k], a[i]);
            }
        }
    }
    swap(a[i + 1], a[tail]);                // Move the pivot to the right place

    // Now the pivot is at i + 1
    return make_pair(k + 1, i + 1);
}

int quickselect(vector<int>& a, int head, int tail, int order) {
    pair<int, int> pivot = partition(a, head, tail);
    if (order < pivot.first)
        return quickselect(a, head, pivot.first - 1, order);
    else if (order > pivot.second)
        return quickselect(a, pivot.second + 1, tail, order);
    else
        return a[order];
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n - 1, n - k);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;
    cout << findKthLargest(nums, k) << endl;

    return 0;
}
