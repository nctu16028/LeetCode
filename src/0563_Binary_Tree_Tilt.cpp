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

void postorderTraversal(TreeNode* root) {
    if (root->left != nullptr) {
        postorderTraversal(root->left);
        root->val += root->left->val;
    }
    if (root->right != nullptr) {
        postorderTraversal(root->right);
        root->val += root->right->val;
    }
}

void preorderTraversal(TreeNode* root, int& tiltSum) {
    if (root == nullptr)
        return;

    int leftSum = (root->left == nullptr) ? 0 : root->left->val;
    int rightSum = (root->right == nullptr) ? 0 : root->right->val;
    tiltSum += max(leftSum - rightSum, rightSum - leftSum);
    preorderTraversal(root->left, tiltSum);
    preorderTraversal(root->right, tiltSum);
}

int findTilt(TreeNode* root) {
    int output = 0;
    if (root != nullptr) {
        postorderTraversal(root);
        preorderTraversal(root, output);
    }
    return output;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    cout << findTilt(root) << endl;

    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
