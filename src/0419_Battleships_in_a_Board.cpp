#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
    visited[i][j] = true;
    if (i > 0 && board[i - 1][j] == 'X' && !visited[i - 1][j])
        dfs(board, visited, i - 1, j);
    if (i < board.size() - 1 && board[i + 1][j] == 'X' && !visited[i + 1][j])
        dfs(board, visited, i + 1, j);
    if (j > 0 && board[i][j - 1] == 'X' && !visited[i][j - 1])
        dfs(board, visited, i, j - 1);
    if (j < board[0].size() - 1 && board[i][j + 1] == 'X' && !visited[i][j + 1])
        dfs(board, visited, i, j + 1);
}

int countBattleships(vector<vector<char>>& board) {
    int output = 0;    
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'X' && !visited[i][j]) {
                dfs(board, visited, i, j);
                output++;
            }
        }
    }

    return output;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    cout << countBattleships(board) << endl;

    return 0;
}
