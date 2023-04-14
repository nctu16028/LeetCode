#include <iostream>
#include <vector>
using namespace std;

bool isValidAns(const vector<int>& nums, const int& k, const int& candidate)
{
    int numOfSplits = 1, splitSum = 0;
    for (auto& num : nums)
    {
        splitSum += num;
        if (splitSum > candidate)
        {
            numOfSplits++;
            splitSum = num;
        }
    }

    return (numOfSplits <= k);
}

int splitArray(vector<int>& nums, int k)
{
    int n = nums.size();
    int maxVal = 0, totalSum = 0;
    for (auto& num : nums)
    {
        maxVal = max(maxVal, num);
        totalSum += num;
    }

    if (k == 1)
        return totalSum;
    else if (k == n)
        return maxVal;

    // Use binary search to find the minimized largest sum of the split (maxVal <= ans <= totalSum)
    int left = maxVal, right = totalSum, output;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (isValidAns(nums, k, mid))
        {
            output = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return output;
}

/*int splitArray(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> prefixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i];

    int totalSum = prefixSum[n - 1];
    if (k == 1)
        return totalSum;

    // Make the subarray sums as close as to the arithmetic mean w.r.t. the number of subarrays
    vector<int> splitPos(k);    // splitPos[j] is the index that the j-th subarray ends with
    for (int j = 0; j < k; j++)
    {
        int i = (j == 0) ? 0 : (splitPos[j - 1] + 1);
        double splitValue = ((double)totalSum / k) * (j + 1);
        while (i < n - (k - j) && prefixSum[i + 1] <= splitValue)
            i++;
        splitPos[j] = (i < n - (k - j) && prefixSum[i + 1] - splitValue < splitValue - prefixSum[i]) ? (i + 1) : i;
        cout << "splitPos[" << j << "] = " << splitPos[j] << endl;
    }

    int output = prefixSum[splitPos[0]];
    for (int j = 1; j < k; j++)
    {
        if (prefixSum[splitPos[j]] - prefixSum[splitPos[j - 1]] > output)
            output = prefixSum[splitPos[j]] - prefixSum[splitPos[j - 1]];
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
    cout << splitArray(nums, k) << endl;

    return 0;
}
