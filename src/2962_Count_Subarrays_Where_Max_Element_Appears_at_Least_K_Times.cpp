#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int max_val = 0;
    for (const auto &num : nums) {
        if (num > max_val)
            max_val = num;
    }

    int n = nums.size();
    int num_max_vals = 0;
    vector<int> max_val_indices(n, 0);
    for (int i = 0; i < n; i++) {
        if (nums[i] == max_val) {
            max_val_indices[num_max_vals] = i;
            num_max_vals++;
        }
    }

    long long counter = 0;
    for (int left = 0; left < num_max_vals - (k - 1); left++) {
        int right = left + (k - 1);
        long long left_extension_choices = max_val_indices[left] + 1;
        long long right_extension_choices = ((right + 1 < num_max_vals) ? max_val_indices[right + 1] : n) - max_val_indices[right];
        counter += (left_extension_choices * right_extension_choices);
    }

    return counter;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;
    cout << countSubarrays(nums, k) << endl;

    return 0;
}
