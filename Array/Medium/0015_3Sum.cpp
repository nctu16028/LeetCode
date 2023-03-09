#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());     // sort the array first so that each for-loop iteration can run in O(n)

    vector<vector<int>> ans;
    for (int ix = 0; ix < nums.size() - 2; ix++)
    {
        if (ix > 0 && nums[ix] == nums[ix - 1])
            continue;

        // Reduce to TwoSum problem
        int target = -nums[ix];
        int left = ix + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                left++;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
            }
            else if (nums[left] + nums[right] > target)
            {
                right--;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else    // find a solution
            {
                ans.push_back(vector<int>{nums[ix], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<int>> ans = threeSum(nums);
    cout << "[";
    if (ans.size() > 0)
    {
        cout << "[" << ans[0][0];
        for (int j = 1; j < ans[0].size(); j++)
            cout << ", " << ans[0][j];
        cout << "]";
    }
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
