#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> accMatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        accMatrix.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    accMatrix[0][0] = matrix[0][0];
                else if (i == 0)
                    accMatrix[0][j] = accMatrix[0][j - 1] + matrix[0][j];
                else if (j == 0)
                    accMatrix[i][0] = accMatrix[i - 1][0] + matrix[i][0];
                else
                    accMatrix[i][j] = (accMatrix[i - 1][j] + accMatrix[i][j - 1] - accMatrix[i - 1][j - 1]) + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return accMatrix[row2][col2];
        else if (row1 == 0)
            return accMatrix[row2][col2] - accMatrix[row2][col1 - 1];
        else if (col1 == 0)
            return accMatrix[row2][col2] - accMatrix[row1 - 1][col2];
        else
            return accMatrix[row2][col2] - accMatrix[row2][col1 - 1] - accMatrix[row1 - 1][col2] + accMatrix[row1 - 1][col1 - 1];
    }
};

int main()
{
    vector<vector<int>> matrix({
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    });
    NumMatrix* numMatrix = new NumMatrix(matrix);
    cout << numMatrix->sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix->sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix->sumRegion(1, 2, 2, 4) << endl;

    return 0;
}
