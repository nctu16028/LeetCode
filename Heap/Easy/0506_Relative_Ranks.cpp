#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score)
{
    int n = score.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(make_pair(score[i], i));

    vector<string> output(n);
    int order = 1;
    while (!pq.empty())
    {
        if (order == 1)
            output[pq.top().second] = "Gold Medal";
        else if (order == 2)
            output[pq.top().second] = "Silver Medal";
        else if (order == 3)
            output[pq.top().second] = "Bronze Medal";
        else
            output[pq.top().second] = to_string(order);
        pq.pop();
        order++;
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> score(n);
    for (int i = 0; i < n; i++)
        cin >> score[i];

    vector<string> ans = findRelativeRanks(score);
    cout << "[\"" << ans[0] << "\"";
    for (int i = 1; i < ans.size(); i++)
        cout << ", \"" << ans[i] << "\"";
    cout << "]" << endl;

    return 0;
}
