#include <iostream>
#include <vector>
using namespace std;

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> diff_arr(n + 1, 0);
    diff_arr[0] = nums[0] - 0;
    for (int i = 1; i < n; i++)
        diff_arr[i] = nums[i] - nums[i - 1];
    diff_arr[n] = 0 - nums[n - 1];

    for (const auto& query : queries) {
        diff_arr[query[0]]--;
        diff_arr[query[1] + 1]++;
    }

    int flag = diff_arr[0];
    for (int i = 0; i < n; i++) {
        if (flag > 0)
            return false;
        flag += diff_arr[i + 1];
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];
    cout << (isZeroArray(nums, queries) ? "true" : "false") << endl;

    return 0;
}
