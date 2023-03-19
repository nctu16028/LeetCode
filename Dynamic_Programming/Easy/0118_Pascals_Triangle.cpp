#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> output(numRows);
    output[0] = vector<int>(1, 1);
    if (numRows > 1)
    {
        output[1] = vector<int>(2, 1);
        for (int i = 2; i < numRows; i++)
        {
            output[i] = vector<int>(i+1, 1);
            for (int j = 1; j < i; j++)
                output[i][j] = output[i-1][j-1] + output[i-1][j];
        }
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans = generate(n);
    cout << "[";
    cout << "[" << ans[0][0];
    for (int j = 1; j < ans[0].size(); j++)
        cout << ", " << ans[0][j];
    cout << "]";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
