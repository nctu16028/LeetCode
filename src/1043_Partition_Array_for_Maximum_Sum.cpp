#include <iostream>
#include <vector>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> intervalMax(n, vector<int>(n, 0));
    for (int width = 0; width < n; width++)
    {
        for (int i = 0; i + width < n; i++)
        {
            if (width == 0)
                intervalMax[i][i + width] = arr[i];
            else
                intervalMax[i][i + width] = max(intervalMax[i][i + width - 1], intervalMax[i + 1][i + width]);
        }
    }

    vector<vector<int>> dpTable(n, vector<int>(n, 0));
    for (int width = 0; width < n; width++)
    {
        for (int i = 0; i + width < n; i++)
        {
            if (width < k)
                dpTable[i][i + width] = intervalMax[i][i + width] * (width + 1);
            for (int mid = i; mid < i + width; mid++)
                dpTable[i][i + width] = max(dpTable[i][i + width], dpTable[i][mid] + dpTable[mid + 1][i + width]);
        }
    }

    return dpTable[0][n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSumAfterPartitioning(arr, k) << endl;

    return 0;
}
