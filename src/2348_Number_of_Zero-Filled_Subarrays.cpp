#include <iostream>
#include <vector>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long output = 0;
    if (nums[0] == 0)
        nums[0] = 1;
    else
        nums[0] = 0;
    output += nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 0)
            nums[i] = nums[i - 1] + 1;
        else
            nums[i] = 0;
        output += nums[i];
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << zeroFilledSubarray(nums) << endl;

    return 0;
}
