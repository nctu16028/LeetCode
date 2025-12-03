#include <iostream>
#include <vector>
using namespace std;

bool rowBinarySearch(const vector<vector<int>>& matrix, int target, int jMin, int jMax, int row) {
    while (jMin <= jMax) {
        int jMid = (jMin + jMax) / 2;
        if (matrix[row][jMid] < target)
            jMin = jMid + 1;
        else if (matrix[row][jMid] > target)
            jMax = jMid - 1;
        else
            return true;
    }
    return false;
}

bool columnBinarySearch(const vector<vector<int>>& matrix, int target, int iMin, int iMax, int col) {
    while (iMin <= iMax) {
        int iMid = (iMin + iMax) / 2;
        if (matrix[iMid][col] < target)
            iMin = iMid + 1;
        else if (matrix[iMid][col] > target)
            iMax = iMid - 1;
        else
            return true;
    }
    return false;
}

bool searchMatrixRecursively(const vector<vector<int>>& matrix, int target, int iMin, int iMax, int jMin, int jMax) {
    int numRows = iMax - iMin + 1;
    int numCols = jMax - jMin + 1;
    if (numRows == 1 && numCols == 1)
        return (matrix[iMin][jMin] == target);
    else if (numRows == 1)
        return rowBinarySearch(matrix, target, jMin, jMax, iMin);
    else if (numCols == 1)
        return columnBinarySearch(matrix, target, iMin, iMax, jMin);

    int diagMin = 0;
    int diagMax = min(numRows, numCols) - 1;
    if (target < matrix[iMin + diagMin][jMin + diagMin])
        return false;
    else if (matrix[iMin + diagMax][jMin + diagMax] < target) {
        if (iMin + diagMax == iMax && jMin + diagMax == jMax)
            return false;
        else if (iMin + diagMax == iMax)
            return searchMatrixRecursively(matrix, target, iMin, iMax, jMin + diagMax, jMax);
        else if (jMin + diagMax == jMax)
            return searchMatrixRecursively(matrix, target, iMin + diagMax, iMax, jMin, jMax);
    }

    while (diagMin + 1 < diagMax) {
        int diagMid = (diagMin + diagMax) / 2;
        if (matrix[iMin + diagMid][jMin + diagMid] < target)
            diagMin = diagMid;
        else if (matrix[iMin + diagMid][jMin + diagMid] > target)
            diagMax = diagMid;
        else
            return true;
    }
    if (matrix[iMin + diagMin][jMin + diagMin] == target || matrix[iMin + diagMax][jMin + diagMax] == target)
        return true;

    // matrix[iMin][jMin] ~ matrix[iMin + diagMin][jMin + diagMin] < target
    // matrix[iMin + diagMax][jMin + diagMax] ~ matrix[iMax][jMax] > target
    bool found = (
        searchMatrixRecursively(matrix, target, iMin + diagMax, iMax, jMin, jMin + diagMin) ||
        searchMatrixRecursively(matrix, target, iMin, iMin + diagMin, jMin + diagMax, jMax)
    );
    return found;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    return searchMatrixRecursively(matrix, target, 0, m - 1, 0, n - 1);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int target;
    cin >> target;
    cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
