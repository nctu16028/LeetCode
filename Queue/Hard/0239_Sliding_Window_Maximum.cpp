#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> output;
    deque<int> mq;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!mq.empty() && mq.front() <= i - k)
            mq.pop_front();     // remove expired data
        while (!mq.empty() && nums[i] > nums[mq.back()])
            mq.pop_back();      // maintain monotonic property
        mq.push_back(i);

        if (i >= k - 1)
            output.push_back(nums[mq.front()]);
    }

    return output;
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

    vector<int> ans = maxSlidingWindow(nums, k);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
