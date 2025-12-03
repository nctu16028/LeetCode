#include <iostream>
#include <vector>
using namespace std;

int findGCD(vector<int>& nums) {
    int minVal = nums[0], maxVal = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        minVal = min(nums[i], minVal);
        maxVal = max(nums[i], maxVal);
    }

    while (minVal != 0) {
        int temp = maxVal % minVal;
        maxVal = minVal;
        minVal = temp;
    }

    return maxVal;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << findGCD(nums) << endl;

    return 0;
}
