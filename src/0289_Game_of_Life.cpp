#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> count(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0)
                continue;

            if (i > 0 && j > 0)
                count[i - 1][j - 1]++;
            if (i > 0)
                count[i - 1][j]++;
            if (i > 0 && j < n - 1)
                count[i - 1][j + 1]++;
            if (j > 0)
                count[i][j - 1]++;
            if (j < n - 1)
                count[i][j + 1]++;
            if (i < m - 1 && j > 0)
                count[i + 1][j - 1]++;
            if (i < m - 1)
                count[i + 1][j]++;
            if (i < m - 1 && j < n - 1)
                count[i + 1][j + 1]++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0 && count[i][j] == 3)
                board[i][j] = 1;
            else if (board[i][j] == 1 && (count[i][j] < 2 || count[i][j] > 3))
                board[i][j] = 0;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    gameOfLife(board);
    cout << "[[" << board[0][0];
    for (int j = 1; j < n; j++)
        cout << ", " << board[0][j];
    cout << "]";
    for (int i = 1; i < m; i++) {
        cout << ", [" << board[i][0];
        for (int j = 1; j < n; j++)
            cout << ", " << board[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}
