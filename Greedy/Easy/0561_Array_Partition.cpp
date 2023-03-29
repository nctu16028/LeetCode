#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    int output = 0;
    for (int i = 0; i < nums.size(); i += 2)
        output += nums[i];

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << arrayPairSum(nums) << endl;

    return 0;
}
