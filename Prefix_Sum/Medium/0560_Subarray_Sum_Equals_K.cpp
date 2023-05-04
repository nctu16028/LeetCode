#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i];

    // Brute-force version
    /*int output = 0;
    for (int right = 0; right < n; right++)
    {
        if (prefixSum[right] == k)
            output++;
        for (int left = 1; left <= right; left++)
        {
            if (prefixSum[right] - prefixSum[left - 1] == k)
                output++;
        }
    }*/

    // With hash table
    unordered_map<int, int> sumCount;
    int output = 0;
    for (int right = 0; right < n; right++)
    {
        // Check subarrays ended with nums[right]
        if (prefixSum[right] == k)
            output++;
        if (sumCount.find(prefixSum[right] - k) != sumCount.end())
            // there exist some prefix sums on the left such that prefixSum[right] - prefixSum[left] == k
            output += sumCount[prefixSum[right] - k];

        // Memoize the current prefix sum
        if (sumCount.find(prefixSum[right]) == sumCount.end())
            sumCount.insert({prefixSum[right], 0});
        sumCount[prefixSum[right]]++;
    }

    return output;
}

// Simplified further
/*int subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int> sumCount;
    int output = 0;
    int prefixSum = 0;

    for (int& num : nums)
    {
        prefixSum += num;
        if (prefixSum == k)
            output++;
        if (sumCount.find(prefixSum - k) != sumCount.end())
            output += sumCount[prefixSum - k];

        if (sumCount.find(prefixSum) == sumCount.end())
            sumCount.insert({prefixSum, 0});
        sumCount[prefixSum]++;
    }

    return output;
}*/

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;
    cout << subarraySum(nums, k) << endl;

    return 0;
}
