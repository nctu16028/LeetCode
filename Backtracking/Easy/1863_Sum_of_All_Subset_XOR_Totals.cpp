#include <iostream>
#include <vector>
using namespace std;

void recursiveHelper(int i, int subsetXOR, int& sum, const vector<int>& nums)
{
    if (i == nums.size())
    {
        sum += subsetXOR;
        return;
    }

    recursiveHelper(i + 1, subsetXOR, sum, nums);
    recursiveHelper(i + 1, subsetXOR ^ nums[i], sum, nums);
}

int subsetXORSum(vector<int>& nums)
{
    int output = 0;
    int subsetXOR = 0;
    recursiveHelper(0, subsetXOR, output, nums);

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << subsetXORSum(nums) << endl;

    return 0;
}
