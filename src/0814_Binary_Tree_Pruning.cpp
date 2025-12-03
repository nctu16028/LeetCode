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

void pruneTreeRecursively(TreeNode* root) {
    if (root->left != nullptr) {
        pruneTreeRecursively(root->left);
        if (root->left->left == nullptr && root->left->right == nullptr && root->left->val == 0) {
            TreeNode* temp = root->left;
            root->left = nullptr;
            delete temp;
        }
    }
    if (root->right != nullptr) {
        pruneTreeRecursively(root->right);
        if (root->right->left == nullptr && root->right->right == nullptr && root->right->val == 0) {
            TreeNode* temp = root->right;
            root->right = nullptr;
            delete temp;
        }
    }
}

TreeNode* pruneTree(TreeNode* root) {
    pruneTreeRecursively(root);
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
        TreeNode* temp = root;
        root = nullptr;
        delete temp;
    }
    return root;
}

void deleteNodes(TreeNode* root) {
    if (root->left != nullptr)
        deleteNodes(root->left);
    if (root->right != nullptr)
        deleteNodes(root->right);
    cout << " " << root->val;
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(0);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(0);

    TreeNode* ans = pruneTree(root);
    if (ans != nullptr) {
        deleteNodes(ans);
        cout << endl;
    }

    return 0;
}
