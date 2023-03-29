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

int sumNumbers(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return root->val;

    int output = 0;
    if (root->left != nullptr)
    {
        root->left->val += (root->val * 10);
        output += sumNumbers(root->left);
    }
    if (root->right != nullptr)
    {
        root->right->val += (root->val * 10);
        output += sumNumbers(root->right);
    }

    return output;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    cout << sumNumbers(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
