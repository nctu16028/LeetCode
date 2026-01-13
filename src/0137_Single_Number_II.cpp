#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    vector<int> bit_counter(32, 0);
    for (const int& num : nums) {
        for (int i = 0; i < 32; i++)
            bit_counter[i] += ((num >> i) & 1);     //check whether bit i is 1
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        if (bit_counter[i] % 3)     // if bit_counter[i] is not divisible by 3, then bit i is used by the single element
            ans += (1 << i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << singleNumber(nums) << endl;

    return 0;
}