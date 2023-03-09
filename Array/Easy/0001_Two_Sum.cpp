#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ans(2);
    bool break_flag = false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                break_flag = true;
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }

        if (break_flag)
            break;
    }

    return ans;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = twoSum(nums, t);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
