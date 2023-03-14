#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    unordered_set<int> history;
    for (int i = 0; i < nums.size(); i++)
    {
        if (history.count(nums[i]) == 1)
            return true;
        history.insert(nums[i]);
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
    cout << (containsDuplicate(nums) ? "true" : "false") << endl;

    return 0;
}
