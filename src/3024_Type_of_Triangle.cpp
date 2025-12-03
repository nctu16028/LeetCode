#include <iostream>
#include <vector>
using namespace std;

string triangleType(vector<int>& nums) {
    if (nums[0] == nums[1] && nums[1] == nums[2])
        return "equilateral";
    else if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])
        return "none";
    else if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2])
        return "isosceles";
    else
        return "scalene";
}

int main() {
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    cout << triangleType(nums) << endl;

    return 0;
}
