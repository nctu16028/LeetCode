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

void flatten(TreeNode* root)
{
    if (root == nullptr)
        return;

    flatten(root->left);
    flatten(root->right);

    if (root->left != nullptr)
    {
        TreeNode* leftMax = root->left;
        while (leftMax->right != nullptr)
            leftMax = leftMax->right;
        leftMax->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    flatten(root);
    cout << "[";
    if (root != nullptr)
    {
        cout << root->val;
        TreeNode* curr = root->right;
        while (curr != nullptr)
        {
            cout << ", " << curr->val;
            curr = curr->right;
        }
    }
    cout << "]" << endl;

    while (root != nullptr)
    {
        TreeNode* toDelete = root;
        root = root->right;
        delete toDelete;
    }

    return 0;
}
