#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumGap(vector<int>& nums)
{
    int n = nums.size();
    int minNum = nums[0], maxNum = nums[0];
    for (int i = 1; i < n; i++)
    {
        minNum = min(minNum, nums[i]);
        maxNum = max(maxNum, nums[i]);
    }
    if (n <= 2)
        return maxNum - minNum;

    // The numbers are distributed to n-1 buckets, where the maximum difference within each bucket is at most (maxNum - minNum) / (n-1)
    vector<int> bucketMax(n - 1, -1);   // -1 means there are no numbers in the i-th bucket
    vector<int> bucketMin(n - 1, -1);   // -1 means there are no numbers in the i-th bucket
    for (auto& num : nums)
    {
        double percentile = (double)(num - minNum) / (double)(1 + maxNum - minNum);
        int bucket_idx = (n - 1) * percentile;
        if (bucketMax[bucket_idx] == -1)
        {
            bucketMax[bucket_idx] = num;
            bucketMin[bucket_idx] = num;
        }
        else
        {
            bucketMax[bucket_idx] = max(bucketMax[bucket_idx], num);
            bucketMin[bucket_idx] = min(bucketMin[bucket_idx], num);
        }
    }

    // Since there are n-1 gaps, there must be a gap larger than (maxNum - minNum) / (n-1) by pigeonhole principle
    // Therefore, the maximum gap exsits between the maximum number of some bucket and the minimum number of its next nonempty bucket
    int output = 0;
    int maxOfPrevBucket = bucketMax[0];
    for (int i = 1; i < n - 1; i++)
    {
        if (bucketMax[i] != -1)
        { 
            if (bucketMin[i] - maxOfPrevBucket > output)
                output = bucketMin[i] - maxOfPrevBucket;
            maxOfPrevBucket = bucketMax[i];
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maximumGap(nums) << endl;

    return 0;
}
