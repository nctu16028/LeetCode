#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArrayRecursive(const vector<int>& nums, int head, int tail)
{
    if (head == tail)
        return nums[head];

    int mid = (head + tail) / 2;
    int leftMax = maxSubArrayRecursive(nums, head, mid);
    int rightMax = maxSubArrayRecursive(nums, mid + 1, tail);

    int crossMaxLeftHalf = INT_MIN, crossMaxRightHalf = INT_MIN;
    int temp = 0;
    for (int i = mid; i >= head; i--)
    {
        temp += nums[i];
        crossMaxLeftHalf = max(crossMaxLeftHalf, temp);
    }
    temp = 0;
    for (int i = mid + 1; i <= tail; i++)
    {
        temp += nums[i];
        crossMaxRightHalf = max(crossMaxRightHalf, temp);
    }

    int crossMax = crossMaxLeftHalf + crossMaxRightHalf;
    return max(crossMax, max(leftMax, rightMax));
}

int maxSubArray(vector<int>& nums)
{
    return maxSubArrayRecursive(nums, 0, nums.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << maxSubArray(nums) << endl;

    return 0;
}
