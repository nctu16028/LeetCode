#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int aXORb = 0;
    for (const int& num : nums)
        aXORb ^= num;

    // Use the lowest 1 of (a ^ b) to separate a and b into two groups
    int separator = (aXORb == (1 << 31)) ? aXORb : (aXORb & (-aXORb));
    vector<int> output(2, 0);
    for (const int& num : nums) {
        if (num & separator)
            output[1] ^= num;   // gather the elements with 1 at the separator bit
        else
            output[0] ^= num;   // gather the elements with 0 at the separator bit
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = singleNumber(nums);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}