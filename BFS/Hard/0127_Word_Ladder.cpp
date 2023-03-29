#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    queue<string> visitOrder;
    queue<int> visitLevel;
    visitOrder.push(beginWord);
    visitLevel.push(1);

    while (!visitOrder.empty())
    {
        string currWord = visitOrder.front();
        int currLevel = visitLevel.front();
        visitOrder.pop();
        visitLevel.pop();
        if (currWord == endWord)
            return currLevel;

        for (int i = 0; i < currWord.length(); i++)
        {
            string neighborWord = currWord;
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == currWord[i])
                    continue;
                neighborWord[i] = c;
                if (wordDict.count(neighborWord) > 0)
                {
                    visitOrder.push(neighborWord);
                    visitLevel.push(currLevel + 1);
                    wordDict.erase(neighborWord);
                }
            }
        }
    }

    return 0;
}

int main()
{
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n;
    cin >> n;

    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
        cin >> wordList[i];
    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
