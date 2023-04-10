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

void traverse(TreeNode* root, int& diameter)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        diameter = max(diameter, 0);                                        // a path closed in the subtree rooted at this node
        root->val = 0;                                                      // a path passing through this node and going upward
    }
    else if (root->left == nullptr)
    {
        traverse(root->right, diameter);
        diameter = max(diameter, 1 + root->right->val);                     // a path closed in the subtree rooted at this node
        root->val = 1 + root->right->val;                                   // a path passing through this node and going upward
    }
    else if (root->right == nullptr)
    {
        traverse(root->left, diameter);
        diameter = max(diameter, 1 + root->left->val);                      // a path closed in the subtree rooted at this node
        root->val = 1 + root->left->val;                                    // a path passing through this node and going upward
    }
    else
    {
        traverse(root->left, diameter);
        traverse(root->right, diameter);
        diameter = max(diameter, 2 + root->left->val + root->right->val);   // a path closed in the subtree rooted at this node
        root->val = 1 + max(root->left->val, root->right->val);             // a path passing through this node and going upward
    }
}

int diameterOfBinaryTree(TreeNode* root)
{
    int diameter = 0;
    traverse(root, diameter);
    return diameter;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
