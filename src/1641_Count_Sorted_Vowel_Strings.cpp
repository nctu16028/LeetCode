#include <iostream>
#include <vector>
using namespace std;

int countVowelStrings(int n)
{
    vector<vector<int>> dpTable(n + 1, vector<int>(5, 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < 5; j++)
            dpTable[i][j] = dpTable[i][j - 1] + dpTable[i - 1][j];
    }

    return dpTable[n][4];
}

int main()
{
    int n;
    cin >> n;
    cout << countVowelStrings(n) << endl;

    return 0;
}
