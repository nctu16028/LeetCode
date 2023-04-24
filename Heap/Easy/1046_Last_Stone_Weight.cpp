#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    priority_queue<int> pq;
    for (auto& w : stones)
        pq.push(w);

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (first != second)
            pq.push(first - second);
    }

    if (pq.empty())
        return 0;
    else
        return pq.top();
}

int main()
{
    int n;
    cin >> n;

    vector<int> stones(n);
    for (int i = 0; i < n; i++)
        cin >> stones[i];
    cout << lastStoneWeight(stones) << endl;

    return 0;
}
