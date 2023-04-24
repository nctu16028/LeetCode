#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust)
{
    vector<int> numOfTrusted(n, 0);     // in-degree of vertices
    vector<int> numOfTrusting(n, 0);    // out-degree of vertices
    for (auto& rel : trust)
    {
        numOfTrusting[rel[0] - 1]++;    // increase the out-degree of rel[0] by 1
        numOfTrusted[rel[1] - 1]++;     // increase the in-degree of rel[1] by 1
    }

    int judge = -1;
    for (int i = 0; i < n; i++)
    {
        if (numOfTrusted[i] == n - 1 && numOfTrusting[i] == 0)
        {
            judge = i + 1;
            break;
        }
    }

    return judge;
}

int main()
{
    int n, nE;
    cin >> n >> nE;

    vector<vector<int>> trust(nE, vector<int>(2));
    for (int i = 0; i < nE; i++)
        cin >> trust[i][0] >> trust[i][1];
    cout << findJudge(n, trust) << endl;

    return 0;
}
