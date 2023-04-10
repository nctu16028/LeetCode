#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int upwardBound = 0;
    int downwardBound = m;
    int leftBound = -1;
    int rightBound = n;
    vector<int> output;

    int i = 0, j = 0;
    int direction = 0;      // 0: >; 1: v; 2: <; 3: ^
    while (output.size() < m * n)
    {
        output.push_back(matrix[i][j]);
        if (direction == 0)
        {
            if (j == rightBound - 1)
            {
                direction = 1;
                rightBound--;
                i++;
            }
            else
                j++;
        }
        else if (direction == 1)
        {
            if (i == downwardBound - 1)
            {
                direction = 2;
                downwardBound--;
                j--;
            }
            else
                i++;
        }
        else if (direction == 2)
        {
            if (j == leftBound + 1)
            {
                direction = 3;
                leftBound++;
                i--;
            }
            else
                j--;
        }
        else
        {
            if (i == upwardBound + 1)
            {
                direction = 0;
                upwardBound++;
                j++;
            }
            else
                i--;
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

    vector<int> ans = spiralOrder(matrix);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
