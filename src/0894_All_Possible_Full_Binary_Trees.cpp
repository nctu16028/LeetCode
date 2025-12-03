#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> allPossibleFBT(int n)
{
    if (n % 2 == 0)
        return vector<TreeNode*>();

    int numLeafNodes = n / 2;
    vector<vector<TreeNode*>> subtreeLists(numLeafNodes + 1, vector<TreeNode*>());
    TreeNode* temp = new TreeNode();
    subtreeLists[0].push_back(temp);

    for (int l = 1; l <= numLeafNodes; l++)
    {
        for (int i = 0, j = l - 1; i < l; i++, j--)
        {
            for (auto ti : subtreeLists[i])
            {
                for (auto tj : subtreeLists[j])
                {
                    temp = new TreeNode();
                    temp->left = ti;
                    temp->right = tj;
                    subtreeLists[l].push_back(temp);
                }
            }
        }
    }

    return subtreeLists[numLeafNodes];
}

void deleteTree(TreeNode* root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void clearNodes(vector<TreeNode*>& list)
{
    for (int i = 0; i < list.size(); i++)
        deleteTree(list[i]);
}

int main()
{
    int n;
    cin >> n;

    vector<TreeNode*> ans = allPossibleFBT(n);
    cout << ans.size() << endl;
    clearNodes(ans);

    return 0;
}
