#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int mid_i = mid / n;
        int mid_j = mid % n;
        if (matrix[mid_i][mid_j] < target)
            left = mid + 1;
        else if (matrix[mid_i][mid_j] > target)
            right = mid - 1;
        else
            return true;
    }

    return false;
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

    int target;
    cin >> target;
    cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    return 0;
}
