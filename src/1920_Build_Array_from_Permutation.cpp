#include <iostream>
#include <vector>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    const int NUM_UB = 1000;
    for (int i = 0; i < nums.size(); i++) 
        nums[i] += (NUM_UB * (nums[nums[i]] % NUM_UB));

    // nums[i] = old_nums[i] + NUM_UB * new_nums[i]
    for (int i = 0; i < nums.size(); i++) 
        nums[i] /= NUM_UB;

    return nums;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = buildArray(nums);
    cout << "[" << ans[0];
    for (int i = 1; i < n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
