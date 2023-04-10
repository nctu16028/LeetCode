#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int n = nums.size();
    if (target <= nums[0])
        return 0;
    if (target > nums[n - 1])
        return n;

    int left = 0, right = n - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid;
        else if (nums[mid] > target)
            right = mid;
        else
            return mid;
    }

    return right;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cin >> target;
    cout << searchInsert(nums, target) << endl;

    return 0;
}
