#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums)
{
    // nums = [ (zeros) | (ones) | (unread numbers) | (twos) ]
    int zeroBound = 0, oneBound = 0, twoBound = nums.size();
    for (; oneBound < twoBound; oneBound++)
    {
        while (oneBound < twoBound && nums[oneBound] == 2)
        {
            twoBound--;
            swap(nums[oneBound], nums[twoBound]);
        }
        if (nums[oneBound] == 0)
        {
            swap(nums[oneBound], nums[zeroBound]);
            zeroBound++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sortColors(nums);
    cout << "[" << nums[0];
    for (int i = 1; i < n; i++)
        cout << ", " << nums[i];
    cout << "]" << endl;

    return 0;
}
