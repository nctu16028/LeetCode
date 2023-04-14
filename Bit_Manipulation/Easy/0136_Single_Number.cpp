#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums)
{
    int output = 0;
    for (auto& num : nums)
        output ^= num;  // the effect of some number would be cancelled out if it appears twice

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << singleNumber(nums) << endl;

    return 0;
}
