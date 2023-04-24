#include <iostream>
#include <vector>
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    int output = n;
    vector<int> cpnRep(n, -1);      // cpnRep[i] == -1 means i is an isolated vertex
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!isConnected[i][j])
                continue;

            // Connect the components
            if (cpnRep[i] == -1 && cpnRep[j] == -1)
            {
                cpnRep[i] = i;
                cpnRep[j] = i;
                output--;
            }
            else if (cpnRep[i] == -1)
            {
                cpnRep[i] = cpnRep[j];
                output--;
            }
            else if (cpnRep[j] == -1)
            {
                cpnRep[j] = cpnRep[i];
                output--;
            }
            else
            {
                int repI = cpnRep[i];
                while (repI != cpnRep[repI]) repI = cpnRep[repI];   // trace to the root representative of i
                int repJ = cpnRep[j];
                while (repJ != cpnRep[repJ]) repJ = cpnRep[repJ];   // trace to the root representative of j
                if (repI != repJ)
                {
                    cpnRep[max(repI, repJ)] = min(repI, repJ);
                    output--;
                }
            }
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n);
    for (int i = 0; i < n; i++)
    {
        isConnected[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> isConnected[i][j];
    }
    cout << findCircleNum(isConnected) << endl;

    return 0;
}
