#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int n = nums.size();
    int output = INT_MIN;

    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod *= nums[i];
        output = max(output, prod);
        if (prod == 0)
            prod = 1;
    }

    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod *= nums[i];
        output = max(output, prod);
        if (prod == 0)
            prod = 1;
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
    cout << maxProduct(nums) << endl;

    return 0;
}
