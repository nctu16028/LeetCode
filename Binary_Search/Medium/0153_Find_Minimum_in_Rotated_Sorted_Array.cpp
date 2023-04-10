#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    int left = 0, right = n - 1;
    while (left + 1 < right)
    {
        if (nums[left] < nums[right])   // nums[left..right] is not rotated
            return nums[left];

        int mid = (left + right) / 2;
        if (nums[mid] < nums[left])     // the minimum is between left and mid
            right = mid;
        else                            // the minimum is between mid and right
            left = mid;
    }

    return min(nums[left], nums[right]);    // left + 1 == right when this is reached
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << findMin(nums) << endl;

    return 0;
}
