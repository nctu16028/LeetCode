#include <iostream>
#include <vector>
using namespace std;

int minStartValue(vector<int>& nums)
{
    int runningSum = 0;
    int minRunningSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        runningSum += nums[i];
        if (runningSum < minRunningSum)
            minRunningSum = runningSum;
    }

    return 1 - minRunningSum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << minStartValue(nums) << endl;

    return 0;
}
