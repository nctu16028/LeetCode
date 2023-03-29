#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums)
{
    int evenBound = 0, oddBound = 0;    // nums = [ (even section) | (odd section) | (unread section) ]
    for (; oddBound < nums.size(); oddBound++)
    {
        if (nums[oddBound] % 2 == 0)
        {
            swap(nums[oddBound], nums[evenBound]);
            evenBound++;
        }
    }

    return nums;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = sortArrayByParity(nums);
    cout << "[" << ans[0];
    for (int i = 1; i < n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
