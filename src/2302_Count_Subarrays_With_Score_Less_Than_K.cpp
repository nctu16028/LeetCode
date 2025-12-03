#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    int n = nums.size();
    vector<long long> prefix_sums(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix_sums[i + 1] = prefix_sums[i] + nums[i];

    long long counter = 0;
    int left = 0;
    for (int right = 1; right <= n; right++) {
        while (left < right && (prefix_sums[right] - prefix_sums[left]) * (right - left) >= k)
            left++;
        if ((prefix_sums[right] - prefix_sums[left]) * (right - left) < k)
            counter += (right - left);
    }

    return counter;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long k;
    cin >> k;
    cout << countSubarrays(nums, k) << endl;

    return 0;
}
