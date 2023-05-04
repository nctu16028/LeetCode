#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
        nums[i] += nums[i - 1];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (nums[n - 1] - nums[0] == 0)
                return 0;
        }
        else if (i == n - 1)
        {
            if (nums[n - 2] == 0)
                return n - 1;
        }
        else
        {
            if (nums[i - 1] == nums[n - 1] - nums[i])
                return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << pivotIndex(nums) << endl;

    return 0;
}
