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

int sumOfLeftLeavesHelper(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return root->val;

    int output = 0;
    if (root->left != nullptr)
        output += sumOfLeftLeavesHelper(root->left);
    if (root->right != nullptr && !(root->right->left == nullptr && root->right->right == nullptr))
        output += sumOfLeftLeavesHelper(root->right);

    return output;
}

int sumOfLeftLeaves(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return 0;

    int output = 0;
    if (root->left != nullptr)
        output += sumOfLeftLeavesHelper(root->left);
    if (root->right != nullptr && !(root->right->left == nullptr && root->right->right == nullptr))
        output += sumOfLeftLeavesHelper(root->right);

    return output;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sumOfLeftLeaves(root) << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
