#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> tagRows, tagColumns;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                tagRows.insert(i);
                tagColumns.insert(j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tagRows.count(i) > 0 || tagColumns.count(j) > 0)
                matrix[i][j] = 0;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        matrix.push_back(vector<int>(n));
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    } 

    setZeroes(matrix);
    cout << "[";
    cout << "[" << matrix[0][0];
    for (int j = 1; j < matrix[0].size(); j++)
        cout << ", " << matrix[0][j];
    cout << "]";
    for (int i = 1; i < matrix.size(); i++)
    {
        cout << ", [" << matrix[i][0];
        for (int j = 1; j < matrix[i].size(); j++)
            cout << ", " << matrix[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
