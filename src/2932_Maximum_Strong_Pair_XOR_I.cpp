#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int maximumStrongPairXor(vector<int>& nums) {
    int output = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]) && (nums[i] ^ nums[j]) > output)
                output = nums[i] ^ nums[j];
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maximumStrongPairXor(nums) << endl;

    return 0;
}
