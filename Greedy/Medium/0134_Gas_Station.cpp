#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int n = gas.size();
    int checkSum = 0, idx = 0, ansIdx = 0;
    while (true)
    {
        checkSum += (gas[idx] - cost[idx]);
        if (checkSum < 0)   // if the current index causes the sum to become negative, then the potential answer must be located after it
        {
            if (idx + 1 < n && idx + 1 > ansIdx)
            {
                ansIdx = idx + 1;
                idx = ansIdx;
                checkSum = 0;
            }
            else    // no other potential answers can be found
                return -1;
        }
        else
        {
            idx = (idx + 1) % n;
            if (idx == ansIdx)  // if we don't update the potential answer during a full cycle, then it is the true answer
                break;
        }
    }

    return ansIdx;
}

int main()
{
    int n;
    cin >> n;

    vector<int> gas(n);
    for (int i = 0; i < n; i++)
        cin >> gas[i];

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}
