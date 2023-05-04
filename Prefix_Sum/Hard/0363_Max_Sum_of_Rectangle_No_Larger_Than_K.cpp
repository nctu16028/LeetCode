#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// [Reference] https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/solutions/83599/accepted-c-codes-with-explanation-and-references/
int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int output = INT_MIN;
    for (int leftBound = 0; leftBound < n; leftBound++)
    {
        vector<int> rowPrefixSum(m, 0);
        for (int currCol = leftBound; currCol < n; currCol++)
        {
            int accSum = 0;
            set<int> validPrefixSum;
            for (int i = 0; i < m; i++)
            {
                validPrefixSum.insert(accSum);      // 0 is also inserted in
                rowPrefixSum[i] += matrix[i][currCol];
                accSum += rowPrefixSum[i];

                auto it = lower_bound(validPrefixSum.begin(), validPrefixSum.end(), accSum - k);
                if (it != validPrefixSum.end())     // there exist some prefix sums such that accSum - (one of these) <= k
                    output = max(output, accSum - (*it));
            }
        }
    }

    return output;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int k;
    cin >> k;
    cout << maxSumSubmatrix(matrix, k) << endl;

    return 0;
}
