#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());     // sort the array first so that each for-loop iteration can run in O(n)

    int ans = nums[0] + nums[1] + nums[2];
    int min_diff = 100000;
    for (int ix = 0; ix < nums.size() - 2; ix++)
    {
        // Reduce to TwoSum problem
        int target_twosum = target - nums[ix];
        int left = ix + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            int twosum = nums[left] + nums[right];
            if (twosum < target_twosum)
            {
                if (target_twosum - twosum < min_diff)
                {
                    min_diff = target_twosum - twosum;
                    ans = nums[ix] + twosum;
                }
                left++;
            }
            else if (twosum > target_twosum)
            {
                if (twosum - target_twosum < min_diff)
                {
                    min_diff = twosum - target_twosum;
                    ans = nums[ix] + twosum;
                }
                right--;
            }
            else    // find an exact solution
                return target;
        }
    }

    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << threeSumClosest(nums, target) << endl;

    return 0;
}
