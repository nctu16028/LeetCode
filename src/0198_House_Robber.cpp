#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums)
{
    int output = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i >= 3)
            nums[i] = max(max(nums[i] + nums[i - 3], nums[i] + nums[i - 2]), nums[i - 1]);
        else if (i == 2)
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        output = max(output, nums[i]);
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
    cout << rob(nums) << endl;

    return 0;
}
