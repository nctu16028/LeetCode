#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_set<int> history;
    for (int i = 0; i < nums.size(); i++)
    {
        if (history.count(nums[i]) == 1)
            return true;

        if (i >= k)
            history.erase(nums[i - k]);
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

    int k;
    cin >> k;
    cout << (containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;

    return 0;
}
