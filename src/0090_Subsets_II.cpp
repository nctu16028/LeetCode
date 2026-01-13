#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;

    for (int mask = 0; mask < (1 << n); mask++) {
        // Skip the duplicate subset
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if ((mask & (1 << i)) && !(mask & (1 << (i - 1))) && nums[i] == nums[i - 1]) {
                valid = false;
                break;
            }
        }
        if (!valid)
            continue;

        // Add the valid subset to the output list
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                temp.push_back(nums[i]);
        }
        output.push_back(temp);
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = subsetsWithDup(nums);
    cout << "[[]";
    for (int i = 1; i < ans.size(); i++) {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
