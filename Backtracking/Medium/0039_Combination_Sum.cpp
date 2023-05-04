#include <iostream>
#include <vector>
using namespace std;

void recursiveHelper(const vector<int>& candidates, int candidateStart, int target, vector<int>& combination, vector<vector<int>>& combList)
{
    if (target == 0 && !combination.empty())
    {
        combList.push_back(combination);
        return;
    }

    for (int i = candidateStart; i < candidates.size(); i++)
    {
        if (candidates[i] <= target)
        {
            combination.push_back(candidates[i]);
            recursiveHelper(candidates, i, target - candidates[i], combination, combList);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> output;
    vector<int> combination;
    recursiveHelper(candidates, 0, target, combination, output);

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(candidates, target);
    cout << "[";
    if (!ans.empty())
    {
        cout << "[" << ans[0][0];
        for (int j = 1; j < ans[0].size(); j++)
            cout << ", " << ans[0][j];
        cout << "]";
        for (int i = 1; i < ans.size(); i++)
        {
            cout << ", [" << ans[i][0];
            for (int j = 1; j < ans[i].size(); j++)
                cout << ", " << ans[i][j];
            cout << "]";
        }
    }
    cout << "]" << endl;

    return 0;
}
