#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();
    int product = 1;
    int numOfZeros = 0;
    int zeroPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            numOfZeros++;
            zeroPos = i;
        }
        else
            product *= nums[i];
    }

    vector<int> output(n, 0);
    if (numOfZeros == 1)
        output[zeroPos] = product;
    else if (numOfZeros == 0)
    {
        for (int i = 0; i < n; i++)
            output[i] = product / nums[i];
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans = productExceptSelf(nums);
    cout << "[" << ans[0];
    for (int i = 1; i < n; i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
