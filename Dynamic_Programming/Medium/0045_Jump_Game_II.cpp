#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp_table(n, 10000);
    dp_table[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int k = nums[i];
        for (int j = i + 1; j <= i + k && j < n; j++)
            dp_table[i] = min(dp_table[i], dp_table[j] + 1);
    }

    return dp_table[0];
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << jump(nums) << endl;

    return 0;
}
