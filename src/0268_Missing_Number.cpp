#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    for (const auto& num : nums)
        sum -= num;

    return sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << missingNumber(nums) << endl;

    return 0;
}
