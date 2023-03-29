#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(vector<int>& nums)
{
    int minNum = INT_MAX, midNum = INT_MAX;
    for (auto& num : nums)
    {
        if (num < minNum)
            minNum = num;
        else if (num > minNum && num < midNum)  // happens only when minNum != INT_MAX
            midNum = num;
        else if (num > midNum)  // happens only when minNum != INT_MAX and midNum != INT_MAX
            return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << (increasingTriplet(nums) ? "true" : "false") << endl;

    return 0;
}
