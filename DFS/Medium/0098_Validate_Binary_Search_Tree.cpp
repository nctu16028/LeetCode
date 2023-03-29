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

bool isValidBST(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;

    if (root->left != nullptr)
    {
        if (!isValidBST(root->left))
            return false;

        TreeNode* leftMax = root->left;
        while (leftMax->right != nullptr)
            leftMax = leftMax->right;
        if (leftMax->val >= root->val)
            return false;
    }

    if (root->right != nullptr)
    {
        if (!isValidBST(root->right))
            return false;

        TreeNode* rightMin = root->right;
        while (rightMin->left != nullptr)
            rightMin = rightMin->left;
        if (rightMin->val <= root->val)
            return false;
    }

    return true;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    cout << (isValidBST(root) ? "true" : "false") << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
