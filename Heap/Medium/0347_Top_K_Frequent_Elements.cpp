#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> freq;
    for (auto& num : nums)
    {
        if (freq.count(num) == 0)
            freq.insert({num, 1});
        else
            freq[num]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto& pair : freq)
        pq.push(make_pair(pair.second, pair.first));

    vector<int> output;
    while (k--)
    {
        output.push_back(pq.top().second);
        pq.pop();
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

    vector<int> ans = topKFrequent(nums, k);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
