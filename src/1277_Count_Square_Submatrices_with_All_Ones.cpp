#include <iostream>
#include <vector>
using namespace std;

int countSquares(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> acc(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
                acc[i][j] = matrix[i][j] + acc[i - 1][j] + acc[i][j - 1] - acc[i - 1][j - 1];
            else if (i > 0)
                acc[i][j] = matrix[i][j] + acc[i - 1][j];
            else if (j > 0)
                acc[i][j] = matrix[i][j] + acc[i][j - 1];
            else
                acc[i][j] = matrix[i][j];
        }
    }

    int output = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int size = 1; i - size + 1 >= 0 && j - size + 1 >= 0; size++)
            {
                int subMatrixSum;
                if (i - size + 1 > 0 && j - size + 1 > 0)
                    subMatrixSum = acc[i][j] - acc[i - size][j] - acc[i][j - size] + acc[i - size][j - size];
                else if (i - size + 1 > 0)
                    subMatrixSum = acc[i][j] - acc[i - size][j];
                else if (j - size + 1 > 0)
                    subMatrixSum = acc[i][j] - acc[i][j - size];
                else
                    subMatrixSum = acc[i][j];

                if (subMatrixSum == size * size)
                    output++;
            }
        }
    }

    return output;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << countSquares(matrix) << endl;

    return 0;
}
