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

TreeNode* sortedArrayToBST_helper(vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left + 1) / 2;
    TreeNode* newRoot = new TreeNode(nums[mid]);
    newRoot->left = sortedArrayToBST_helper(nums, left, mid - 1);
    newRoot->right = sortedArrayToBST_helper(nums, mid + 1, right);

    return newRoot;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return sortedArrayToBST_helper(nums, 0, nums.size() - 1);
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    TreeNode* ans = sortedArrayToBST(nums);
    printAndDeleteNode(ans);
    cout << endl;

    return 0;
}
