#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arithmeticTriplets(vector<int>& nums, int diff)
{
    int output = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = lower_bound(nums.begin(), nums.end(), nums[i] + diff) - nums.begin();
        if (j < nums.size() && nums[j] - nums[i] == diff)
        {
            int k = lower_bound(nums.begin(), nums.end(), nums[j] + diff) - nums.begin();
            if (k < nums.size() && nums[k] - nums[j] == diff)
                output++;
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

    int diff;
    cin >> diff;
    cout << arithmeticTriplets(nums, diff) << endl;

    return 0;
}
