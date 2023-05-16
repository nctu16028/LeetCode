#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums)
{
    int output = nums.size();
    int leftBound = 0, windowSum = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        windowSum += nums[right];
        while (windowSum >= target && leftBound <= right)
        {
            output = min(output, right - leftBound + 1);
            target += nums[leftBound];
            leftBound++;
        }
    }

    if (leftBound == 0 && output == nums.size())
        return 0;
    else
        return output;
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}
