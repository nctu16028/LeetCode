#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBalanced(TreeNode* root)
{
    if (root == nullptr)
        return true;

    if (!isBalanced(root->left))
        return false;

    if (!isBalanced(root->right))
        return false;

    if (root->left == nullptr && root->right == nullptr)
        root->val = 0;
    else if (root->left == nullptr)
    {
        if (root->right->val > 0)
            return false;
        root->val = 1 + root->right->val;
    }
    else if (root->right == nullptr)
    {
        if (root->left->val > 0)
            return false;
        root->val = 1 + root->left->val;
    }
    else
    {
        if (root->left->val - root->right->val > 1 || root->right->val - root->left->val > 1)
            return false;
        root->val = 1 + max(root->left->val, root->right->val);
    }

    return true;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << (isBalanced(root) ? "true" : "false") << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
