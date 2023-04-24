#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int large1 = 0, large2 = 0;
    for (auto& num : nums)
    {
        if (num > large1)
        {
            large2 = large1;
            large1 = num;
        }
        else if (num > large2)
            large2 = num;
    }

    return (large1 - 1) * (large2 - 1);
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
