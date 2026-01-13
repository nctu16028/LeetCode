#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs_subtreeSum(TreeNode* root) {
    if (root->left != nullptr) {
        dfs_subtreeSum(root->left);
        root->val += root->left->val;
    }
    if (root->right != nullptr) {
        dfs_subtreeSum(root->right);
        root->val += root->right->val;
    }
}

void dfs_maxProduct(TreeNode* root, int& maxProductNodeVal, const int& target) {
    if (abs(root->val - target) < abs(maxProductNodeVal - target))
        maxProductNodeVal = root->val;

    if (root->left != nullptr)
        dfs_maxProduct(root->left, maxProductNodeVal, target);
    if (root->right != nullptr)
        dfs_maxProduct(root->right, maxProductNodeVal, target);
}

int maxProduct(TreeNode* root) {
    dfs_subtreeSum(root);
    int maxProductNodeVal = root->val;
    int target = root->val / 2;
    dfs_maxProduct(root, maxProductNodeVal, target);

    long long int ans = (1LL * maxProductNodeVal * (root->val - maxProductNodeVal)) % 1000000007;
    return static_cast<int>(ans);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << maxProduct(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}