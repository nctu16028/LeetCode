#include <iostream>
#include <vector>
using namespace std;

int totalHammingDistance(vector<int>& nums) {
    vector<int> bit_counter(32, 0);
    for (const int& num : nums) {
        for (int i = 0; i < 32; i++)
            bit_counter[i] += ((num >> i) & 1);
    }

    int n = nums.size();
    int output = 0;
    for (int i = 0; i < 32; i++) {
        // bc[i] numbers have 1 at bit i, and (n - bc[i]) numbers have 0 at bit i,
        // so there are (bc[i] * (n - bc[i])) pairs of numbers differ in bit i.
        output += (bit_counter[i] * (n - bit_counter[i]));
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << totalHammingDistance(nums) << endl;

    return 0;
}