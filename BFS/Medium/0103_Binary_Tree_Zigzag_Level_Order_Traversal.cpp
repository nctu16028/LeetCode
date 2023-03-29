#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> output;
    if (root == nullptr)
        return output;

    queue<TreeNode*> visitQ;
    queue<int> levelRecord;
    visitQ.push(root);
    levelRecord.push(0);

    int prevLevel = -1;
    while (!visitQ.empty())
    {
        TreeNode* currNode = visitQ.front();
        int currLevel = levelRecord.front();
        visitQ.pop();
        levelRecord.pop();

        if (currLevel > prevLevel)
        {
            output.push_back(vector<int>());
            prevLevel = currLevel;
        }
        if (currLevel % 2 == 1 && output[currLevel].size() > 0)
            output[currLevel].insert(output[currLevel].begin(), currNode->val);
        else
            output[currLevel].push_back(currNode->val);

        if (currNode->left != nullptr)
        {
            visitQ.push(currNode->left);
            levelRecord.push(currLevel + 1);
        }

        if (currNode->right != nullptr)
        {
            visitQ.push(currNode->right);
            levelRecord.push(currLevel + 1);
        }
    }

    return output;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);
    cout << "[";
    if (ans.size() > 0)
        cout << "[" << ans[0][0] << "]";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ", [" << ans[i][0];
        for (int j = 1; j < ans[i].size(); j++)
            cout << ", " << ans[i][j];
        cout << "]";
    }
    cout << "]" << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
