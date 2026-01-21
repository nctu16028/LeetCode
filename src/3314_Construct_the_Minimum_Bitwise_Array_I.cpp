#include <iostream>
#include <vector>
using namespace std;

vector<int> minBitwiseArray(vector<int>& nums) {
    // xx...xx0111...11 = (xx...xx0011...11) | (xx...xx0100...00)
    for (int& num : nums) {
        if ((num & 1) == 0)
            num = -1;
        else {
            int bitMask = 0;
            while ((num >> (bitMask + 1)) & 1)
                bitMask++;
            num = num ^ (1 << bitMask);
        }
    }

    return nums;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = minBitwiseArray(nums);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}