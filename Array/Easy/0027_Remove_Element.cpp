#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int len_after = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (i < nums.size() && nums[i] == val)
            i++;
        if (i < nums.size())
        {
            nums[len_after] = nums[i];
            len_after++;
        }
    }

    return len_after;
}

int main()
{
    int n, val;
    cin >> n >> val;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k = removeElement(nums, val);
    cout << k << ", nums = [" << nums[0];
    for (int i = 1; i < k; i++)
        cout << ", " << nums[i];
    for (int i = k; i < n; i++)
        cout << ", _";
    cout << "]" << endl;

    return 0; 
}
