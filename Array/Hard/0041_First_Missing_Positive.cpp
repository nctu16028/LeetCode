#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    // Move each positive integer k to nums[k-1]
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);   // execute at most n times in total
    }

    // If nums[k-1] is not k, then k is missing
    int k = 1;
    while (k <= n && nums[k-1] == k)
        k++;

    return k;
}


int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << firstMissingPositive(nums) << endl;

    return 0;
}
