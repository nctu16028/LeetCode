#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void reversedInorderTraversal(TreeNode* root, int& sum) {
    if (root == nullptr)
        return;
    reversedInorderTraversal(root->right, sum);
    sum += root->val;
    root->val = sum;
    reversedInorderTraversal(root->left, sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    reversedInorderTraversal(root, sum);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    TreeNode* ans = convertBST(root);
    cout << ans->right->right->right->val << " ";
    delete ans->right->right->right;
    cout << ans->right->right->val << " ";
    delete ans->right->right;
    cout << ans->right->left->val << " ";
    delete ans->right->left;
    cout << ans->right->val << " ";
    delete ans->right;
    cout << ans->left->right->right->val << " ";
    delete ans->left->right->right;
    cout << ans->left->right->val << " ";
    delete ans->left->right;
    cout << ans->left->left->val << " ";
    delete ans->left->left;
    cout << ans->left->val << " ";
    delete ans->left;
    cout << ans->val << endl;
    delete ans;

    return 0;
}
