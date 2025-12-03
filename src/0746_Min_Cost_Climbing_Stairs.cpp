#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    int n = cost.size();
    vector<int> dpTable(n + 1, 0);
    for (int i = 2; i <= n; i++)
        dpTable[i] = min(dpTable[i - 2] + cost[i - 2], dpTable[i - 1] + cost[i - 1]);

    return dpTable[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}
