#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    // Rotate 90 degree closewisely = flip upside-down + transpose
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        matrix.push_back(vector<int>(n));
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    rotate(matrix);
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
