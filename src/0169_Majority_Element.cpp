#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate, count = 0;
    for (const auto& num : nums) {
        if (count == 0)
            candidate = num;
        count = (num == candidate) ? (count + 1) : (count - 1);
    }

    return candidate;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << majorityElement(nums) << endl;

    return 0;
}
