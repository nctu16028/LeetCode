#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> output;
    if (root == nullptr)
        return output;

    // Each node will be pushed into the stack twice: the first is to expand its children, and the second is to read its value
    stack<TreeNode*> visitOrder;
    unordered_set<TreeNode*> expanded;
    visitOrder.push(root);

    while (!visitOrder.empty())
    {
        TreeNode* temp = visitOrder.top();
        visitOrder.pop();

        // If temp can be found in the set, then it is the second visit of temp
        if (expanded.count(temp) > 0)
        {
            output.push_back(temp->val);
            continue;
        }

        if (temp->right != nullptr)
            visitOrder.push(temp->right);
        visitOrder.push(temp);  // push temp for its second visit
        if (temp->left != nullptr)
            visitOrder.push(temp->left);

        expanded.insert(temp);  // finish the first visit of temp
    }

    return output;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);
    cout << "[";
    if (ans.size() > 0)
    {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
