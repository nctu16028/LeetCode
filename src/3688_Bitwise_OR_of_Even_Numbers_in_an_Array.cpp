#include <iostream>
#include <vector>
using namespace std;

int evenNumberBitwiseORs(vector<int>& nums) {
    int output = 0;
    for (const int& num : nums) {
        if ((num & 1) == 0)
            output |= num;
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << evenNumberBitwiseORs(nums) << endl;

    return 0;
}