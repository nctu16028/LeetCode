#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.rbegin(), satisfaction.rend());   // sort decreasingly
    vector<int> prefixSum(n);
    prefixSum[0] = satisfaction[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + satisfaction[i];

    int output = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += prefixSum[i];
        output = max(output, temp);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> satisfaction(n);
    for (int i = 0; i < n; i++)
        cin >> satisfaction[i];
    cout << maxSatisfaction(satisfaction) << endl;

    return 0;
}
