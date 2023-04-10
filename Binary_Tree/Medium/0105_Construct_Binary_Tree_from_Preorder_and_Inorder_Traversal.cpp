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

TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight)
{
    if (preLeft > preRight)
        return nullptr;

    int rootVal = preorder[preLeft];
    int rootPosInorder = inLeft;
    while (inorder[rootPosInorder] != rootVal)
        rootPosInorder++;

    TreeNode* newRoot = new TreeNode(rootVal);
    newRoot->left = buildTreeHelper(preorder, inorder, preLeft + 1, preLeft + (rootPosInorder - inLeft), inLeft, rootPosInorder - 1);
    newRoot->right = buildTreeHelper(preorder, inorder, preLeft + (rootPosInorder - inLeft) + 1, preRight, rootPosInorder + 1, inRight);

    return newRoot;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int n = preorder.size();
    return buildTreeHelper(preorder, inorder, 0, n - 1, 0, n - 1);
}

void printAndDeleteNode(TreeNode* root)
{
    if (root == nullptr)
        return;

    printAndDeleteNode(root->left);
    cout << root->val << " ";
    printAndDeleteNode(root->right);
    delete root;
}

int main()
{
    int n;
    cin >> n;

    vector<int> preorder(n);
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    vector<int> inorder(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    TreeNode* root = buildTree(preorder, inorder);
    printAndDeleteNode(root);
    cout << endl;

    return 0;
}
