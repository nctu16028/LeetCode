#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int subtreePathSum(TreeNode* root, int& maxSum)
{
    if (root == nullptr)
        return 0;

    int maxSumFromLeftPath = max(0, subtreePathSum(root->left, maxSum));    // ignore negative subtree-path-sums
    int maxSumFromRightPath = max(0, subtreePathSum(root->right, maxSum));  // ignore negative subtree-path-sums

    // A path closed in the subtree rooted at this node
    if (root->val + maxSumFromLeftPath + maxSumFromRightPath > maxSum)
        maxSum = root->val + maxSumFromLeftPath + maxSumFromRightPath;

    // A path passing through this node and going upward
    return root->val + max(maxSumFromLeftPath, maxSumFromRightPath);
}

int maxPathSum(TreeNode* root)
{
    int output = INT_MIN;
    subtreePathSum(root, output);
    return output;
}

int main()
{
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
