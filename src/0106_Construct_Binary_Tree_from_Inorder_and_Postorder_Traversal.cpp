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

TreeNode* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
    if (postLeft > postRight)
        return nullptr;

    int rootVal = postorder[postRight];
    int rootPosInorder = inRight;
    while (inorder[rootPosInorder] != rootVal)
        rootPosInorder--;

    TreeNode* newRoot = new TreeNode(rootVal);
    newRoot->left = buildTreeHelper(inorder, postorder, inLeft, rootPosInorder - 1, postLeft, postRight - (inRight - rootPosInorder) - 1);
    newRoot->right = buildTreeHelper(inorder, postorder, rootPosInorder + 1, inRight, postRight - (inRight - rootPosInorder), postRight - 1);

    return newRoot;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    return buildTreeHelper(inorder, postorder, 0, n - 1, 0, n - 1);
}

void printAndDeleteNode(TreeNode* root) {
    if (root == nullptr)
        return;

    printAndDeleteNode(root->left);
    cout << root->val << " ";
    printAndDeleteNode(root->right);
    delete root;
}

int main() {
    int n;
    cin >> n;

    vector<int> inorder(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    vector<int> postorder(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    TreeNode* root = buildTree(inorder, postorder);
    printAndDeleteNode(root);
    cout << endl;

    return 0;
}
