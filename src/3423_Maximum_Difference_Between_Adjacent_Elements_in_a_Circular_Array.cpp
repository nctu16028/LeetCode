#include <iostream>
#include <vector>
using namespace std;

int maxAdjacentDistance(vector<int>& nums) {
    int n = nums.size();
    int output = max(nums[0] - nums[n - 1], nums[n - 1] - nums[0]);
    for (int i = 1; i < n; i++)
        output = max(output, max(nums[i] - nums[i - 1], nums[i - 1] - nums[i]));

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maxAdjacentDistance(nums) << endl;

    return 0;
}
