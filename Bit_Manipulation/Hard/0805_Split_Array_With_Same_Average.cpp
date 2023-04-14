#include <iostream>
#include <vector>
using namespace std;

// Original implementation
/*bool splitArraySameAverage(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return false;

    int totalSum = 0;
    for (auto& num : nums)
        totalSum += num;

    // dpTable[i][j] is true if there exists a subset of length j with sum i
    vector<vector<bool>> dpTable(totalSum + 1, vector<bool>(n + 1, false));
    dpTable[0][0] = true;
    for (auto& num : nums)  // each iteration takes one more element into consideration
    {
        // Since dpTable[i + num][j + 1] depends on the previous state of dpTable[i][j],
        // we update the table in reverse order so that it is logically correct.
        for (int i = totalSum - num; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
                dpTable[i + num][j + 1] = dpTable[i + num][j + 1] || dpTable[i][j];
        }
    }

    // Avg(nums) = Avg(A) = Avg(B) if such A and B exist, so Sum(A) = Sum(nums) / Size(nums) * Size(A)
    for (int j = 1; j < n; j++)
    {
        if ((totalSum * j) % n != 0)    // the target sum is not an integer
            continue;
        int targetSum = totalSum * j / n;
        if (dpTable[targetSum][j])
            return true;
    }

    return false;
}*/

// Optimized with bitsets
bool splitArraySameAverage(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1)
        return false;

    int totalSum = 0;
    for (auto& num : nums)
        totalSum += num;

    // The j-th bit (0-indexed, right-to-left) of dpTable[i] is 1 if there exists a subset of length j with sum i
    vector<int> dpTable(totalSum + 1, 0);
    dpTable[0] |= (1 << 0);
    for (auto& num : nums)  // each iteration takes one more element into consideration
    {
        // Since dpTable[i + num][j + 1] depends on the previous state of dpTable[i][j],
        // we update the table in reverse order so that it is logically correct.
        for (int i = totalSum - num; i >= 0; i--)
            dpTable[i + num] |= (dpTable[i] << 1);
    }

    // Avg(nums) = Avg(A) = Avg(B) if such A and B exist, so Sum(A) = Sum(nums) / Size(nums) * Size(A)
    for (int len = 1; len < n; len++)
    {
        if ((totalSum * len) % n != 0)  // the target sum is not an integer
            continue;
        int targetSum = totalSum * len / n;
        if ((dpTable[targetSum] & (1 << len)) != 0)
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
    cout << (splitArraySameAverage(nums) ? "true" : "false") << endl;

    return 0;
}
