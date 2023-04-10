#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isMatched(const int& m, const int& n, const vector<vector<char>>& board, vector<vector<bool>>& valid, string word, int i, int j)
{
    if (word.empty())
        return true;

    if (i > 0 && valid[i - 1][j] && board[i - 1][j] == word[0])
    {
        valid[i - 1][j] = false;
        if (isMatched(m, n, board, valid, word.substr(1), i - 1, j))
            return true;
        valid[i - 1][j] = true;
    }

    if (i < m - 1 && valid[i + 1][j] && board[i + 1][j] == word[0])
    {
        valid[i + 1][j] = false;
        if (isMatched(m, n, board, valid, word.substr(1), i + 1, j))
            return true;
        valid[i + 1][j] = true;
    }

    if (j > 0 && valid[i][j - 1] && board[i][j - 1] == word[0])
    {
        valid[i][j - 1] = false;
        if (isMatched(m, n, board, valid, word.substr(1), i, j - 1))
            return true;
        valid[i][j - 1] = true;
    }

    if (j < n - 1 && valid[i][j + 1] && board[i][j + 1] == word[0])
    {
        valid[i][j + 1] = false;
        if (isMatched(m, n, board, valid, word.substr(1), i, j + 1))
            return true;
        valid[i][j + 1] = true;
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> valid(m, vector<bool>(n, true));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                valid[i][j] = false;
                if (isMatched(m, n, board, valid, word.substr(1), i, j))
                    return true;
                valid[i][j] = true;
            }
        }
    }

    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<char>> board(m);
    for (int i = 0; i < m; i++)
    {
        board[i] = vector<char>(n);
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    string word;
    cin >> word;
    cout << (exist(board, word) ? "true" : "false") << endl;

    return 0;
}
