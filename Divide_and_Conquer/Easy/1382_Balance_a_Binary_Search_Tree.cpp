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

void gatherNumber(vector<TreeNode*>& nums, TreeNode* root)
{
    if (root == nullptr)
        return;

    gatherNumber(nums, root->left);
    nums.push_back(root);
    gatherNumber(nums, root->right);
    root->left = nullptr;
    root->right = nullptr;
}

TreeNode* buildTreeHelper(const vector<TreeNode*>& nums, int head, int tail)
{
    if (head > tail)
        return nullptr;

    int mid = (head + tail) / 2;
    TreeNode* root = nums[mid];
    root->left = buildTreeHelper(nums, head, mid - 1);
    root->right = buildTreeHelper(nums, mid + 1, tail);
    return root;
}

TreeNode* balanceBST(TreeNode* root)
{
    vector<TreeNode*> nums;
    gatherNumber(nums, root);
    return buildTreeHelper(nums, 0, nums.size() - 1);
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
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    TreeNode* ans = balanceBST(root);
    printAndDeleteNode(ans);
    cout << endl;

    return 0;
}
