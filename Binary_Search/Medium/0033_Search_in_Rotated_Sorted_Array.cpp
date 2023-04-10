#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    int n = nums.size();
    if (nums[0] == target)
        return 0;
    else if (nums[n - 1] == target)
        return n - 1;

    int left = 0, right = n - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;

        if (target < nums[left])
        {
            // nums[left..right] is rotated and target may be in the right section
            if (nums[mid] > target && nums[mid] < nums[left])   // left - boundary - target - mid - right
                right = mid;
            else    // left - boundary - mid - target - right  OR  left - mid - boundary - target - right
                left = mid;
        }
        else if (target > nums[right])
        {
            // nums[left..right] is rotated and target may be in the left section
            if (nums[mid] < target && nums[mid] > nums[right])  // left - mid - target - boundary - right
                left = mid;
            else    // left - target - mid - boundary - right  OR  left - target - boundary - mid - right
                right = mid;
        }
        else
        {
            // nums[left..right] is not rotated
            if (nums[mid] < target)     // left - mid - target - right
                left = mid;
            else                        // left - target - mid - right
                right = mid;
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

    int target;
    cin >> target;
    cout << search(nums, target) << endl;

    return 0;
}
