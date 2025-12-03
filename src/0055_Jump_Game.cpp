#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> canReachLast(n, false);
    canReachLast[n - 1] = true;

    for (int i = n - 2; i >= 0; i--) {
        int k = nums[i];
        for (int j = i + 1; j <= i + k && j < n; j++)
            canReachLast[i] = canReachLast[i] || canReachLast[j];
    }

    return canReachLast[0];
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << (canJump(nums) ? "true" : "false") << endl;

    return 0;
}
