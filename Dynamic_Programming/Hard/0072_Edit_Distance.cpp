#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2)
{
    int len1 = word1.length();
    int len2 = word2.length();
    word1 = "_" + word1;
    word2 = "_" + word2;

    // dp_table[i][j] is the edit distance between word1[1..i] and word2[1..j]
    vector<vector<int>> dp_table(len1 + 1);
    for (int i = 0; i <= len1; i++)
    {
        dp_table[i] = vector<int>(len2 + 1);
        dp_table[i][0] = i;     // the edit distance between word1[1..i] and empty string is the cost of deleting i characters from word1
    }
    for (int j = 0; j <= len2; j++)
        dp_table[0][j] = j;     // the edit distance between empty string and word2[1..j] is the cost of inserting j characters into word1

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (word1[i] == word2[j])
                dp_table[i][j] = dp_table[i - 1][j - 1];
            else
            {
                int insert_cost = dp_table[i][j - 1] + 1;       // the cost of inserting word2[j] into word1
                int delete_cost = dp_table[i - 1][j] + 1;       // the cost of deleting word1[i] from word1
                int replace_cost = dp_table[i - 1][j - 1] + 1;  // the cost of replacing word1[i] with word2[j]
                dp_table[i][j] = min(min(insert_cost, delete_cost), replace_cost);
            }
        }
    }

    return dp_table[len1][len2];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;

    return 0;
}
