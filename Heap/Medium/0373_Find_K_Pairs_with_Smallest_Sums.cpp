#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
    struct cmp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.first + a.second < b.first + b.second;
        }
    };

    // We always keep the k smallest pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;     // max heap
    for (auto& num1 : nums1)
    {
        for (auto& num2 : nums2)
        {
            if (pq.size() < k)
                pq.push(make_pair(num1, num2));
            else if (num1 + num2 < pq.top().first + pq.top().second)    // replace the maximum pair with a smaller one
            {
                pq.pop();
                pq.push(make_pair(num1, num2));
            }
            else
                break;  // since nums2 is ascending, we can ignore the remaining part
        }
    }

    vector<vector<int>> output;
    while (!pq.empty())
    {
        vector<int> temp(2);
        temp[0] = pq.top().first;
        temp[1] = pq.top().second;
        pq.pop();
        output.push_back(temp);
    }
    reverse(output.begin(), output.end());

    return output;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    int k;
    cin >> k;

    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, k);
    cout << "[[" << ans[0][0] << ", " << ans[0][1] << "]";
    for (int i = 1; i < ans.size(); i++)
        cout << ", [" << ans[i][0] << ", " << ans[i][1] << "]";
    cout << "]" << endl;

    return 0;
}
