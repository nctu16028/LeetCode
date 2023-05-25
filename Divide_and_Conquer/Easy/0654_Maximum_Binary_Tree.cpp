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

TreeNode* buildTreeHelper(const vector<int>& nums, int head, int tail)
{
    if (head > tail)
        return nullptr;

    int maxVal = -1, maxIdx = head;
    for (int i = head; i <= tail; i++)
    {
        if (nums[i] > maxVal)
        {
            maxVal = nums[i];
            maxIdx = i;
        }
    }

    TreeNode* root = new TreeNode(maxVal);
    root->left = buildTreeHelper(nums, head, maxIdx - 1);
    root->right = buildTreeHelper(nums, maxIdx + 1, tail);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
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
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    TreeNode* ans = constructMaximumBinaryTree(nums);
    printAndDeleteNode(ans);
    cout << endl;

    return 0;
}
