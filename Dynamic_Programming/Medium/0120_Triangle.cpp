#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size();
    vector<int> dp_curr = triangle[n - 1];
    vector<int> dp_prev = dp_curr;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
            dp_curr[j] = triangle[i][j] + min(dp_prev[j], dp_prev[j + 1]);
        dp_prev = dp_curr;
    }

    return dp_curr[0];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
    {
        triangle[i] = vector<int>(i + 1);
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    }
    cout << minimumTotal(triangle) << endl;

    return 0;
}
