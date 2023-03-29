#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    // Transform the interval objects into endpoint objects
    vector<pair<int, int>> endpoints;
    pair<int, int> temp;
    for (int i = 0; i < intervals.size(); i++)
    {
        temp = make_pair(intervals[i][0], 0);   // starting point
        endpoints.push_back(temp);
        temp = make_pair(intervals[i][1], 1);   // ending point
        endpoints.push_back(temp);
    }

    // Sort the endpoints
    struct
    {
        bool operator()(pair<int, int> a, pair<int, int> b) const
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        }
    } customLess;
    sort(endpoints.begin(), endpoints.end(), customLess);

    // Generate merged intervals from the sorted endpoints
    vector<vector<int>> output;
    vector<int> itv(2);
    int count = 0;
    for (int i = 0; i < endpoints.size(); i++)
    {
        if (endpoints[i].second == 0)
        {
            if (count == 0)     // only consider the leftmost one among a series of s-points
                itv[0] = endpoints[i].first;
            count++;
        }
        else
        {
            count--;
            if (count == 0)     // only consider the rightmost one among a series of e-points
            {
                itv[1] = endpoints[i].first;
                output.push_back(itv);
            }
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        intervals[i] = vector<int>(2);
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> ans = merge(intervals);
    cout << "[[" << ans[0][0] << ", " << ans[0][1] << "]";
    for (int i = 1; i < ans.size(); i++)
        cout << ", [" << ans[i][0] << ", " << ans[i][1] << "]";
    cout << "]" << endl;

    return 0;
}
