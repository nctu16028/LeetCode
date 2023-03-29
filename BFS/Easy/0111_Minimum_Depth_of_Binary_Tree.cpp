#include <iostream>
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

int minDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    queue<TreeNode*> q;
    root->val = 1;
    q.push(root);

    int output;
    while (true)
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left == nullptr && temp->right == nullptr)
        {
            output = temp->val;
            break;
        }

        if (temp->left != nullptr)
        {
            temp->left->val = temp->val + 1;
            q.push(temp->left);
        }

        if (temp->right != nullptr)
        {
            temp->right->val = temp->val + 1;
            q.push(temp->right);
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

    cout << minDepth(root) << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
