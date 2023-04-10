#include <iostream>
#include <vector>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;
        }
    }

    return true;
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
    cout << (isToeplitzMatrix(matrix) ? "true" : "false") << endl;

    return 0;
}
