#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nums[i];

    int maxSum = sum;
    for (int i = k; i < nums.size(); i++)
    {
        sum = sum - nums[i - k] + nums[i];
        if (sum > maxSum)
            maxSum = sum;
    }

    return (double)maxSum / k;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;
    cout << findMaxAverage(nums, k) << endl;

    return 0;
}
