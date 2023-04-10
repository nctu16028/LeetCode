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

void traverse(TreeNode* root, int& minDiff, int& prevVal)
{
    if (root == nullptr)
        return;

    traverse(root->left, minDiff, prevVal);
    if (prevVal != -1)
        minDiff = min(minDiff, root->val - prevVal);
    prevVal = root->val;
    traverse(root->right, minDiff, prevVal);
}

int getMinimumDifference(TreeNode* root)
{
    int minDiff = INT_MAX;
    int prevVal = -1;
    traverse(root, minDiff, prevVal);

    return minDiff;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << getMinimumDifference(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
