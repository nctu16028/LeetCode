#include <iostream>
#include <vector>
using namespace std;

void search(const vector<int>& nums, const int& target, int& left, int& right)
{
    if (left > right || target < nums[left] || target > nums[right])
    {
        left = -1;
        right = -1;
        return;
    }

    int mid = (left + right) / 2;
    if (nums[mid] < target)         // the whole range of target is at right half
    {
        left = mid + 1;
        search(nums, target, left, right);
    }
    else if (nums[mid] > target)    // the whole range of target is at left half
    {
        right = mid - 1;
        search(nums, target, left, right);
    }
    else                            // the range of target is across the midpoint
    {
        if (nums[left] < target)
        {
            int pseudoRight = mid - 1;
            search(nums, target, left, pseudoRight);
            if (left == -1)
                left = mid;
        }
        if (nums[right] > target)
        {
            int pseudoLeft = mid + 1;
            search(nums, target, pseudoLeft, right);
            if (right == -1)
                right = mid;
        }
    }
}

vector<int> searchRange(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    search(nums, target, left, right);

    vector<int> output(2);
    output[0] = left;
    output[1] = right;

    return output;
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

    vector<int> ans = searchRange(nums, target);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
