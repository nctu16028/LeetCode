#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid;
        else if (nums[mid] > target)
            right = mid;
        else
            return mid;
    }

    if (nums[left] == target)
        return left;
    else if (nums[right] == target)
        return right;
    else
        return -1;
}

int main() {
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
