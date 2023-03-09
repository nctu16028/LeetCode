#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int uniq_len = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[uniq_len-1])
        {
            nums[uniq_len] = nums[i];
            uniq_len++;
        }
    }

    return uniq_len;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k = removeDuplicates(nums);
    cout << k << ", nums = [" << nums[0];
    for (int i = 1; i < k; i++)
        cout << ", " << nums[i];
    for (int i = k; i < n; i++)
        cout << ", _";
    cout << "]" << endl;

    return 0; 
}
