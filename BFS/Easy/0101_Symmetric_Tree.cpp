#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
        return true;
    else if (root->left == nullptr || root->right == nullptr)
        return false;

    queue<TreeNode*> leftQ, rightQ;
    leftQ.push(root->left);
    rightQ.push(root->right);

    while (!leftQ.empty())
    {
        TreeNode* lTemp = leftQ.front();
        TreeNode* rTemp = rightQ.front();
        leftQ.pop();
        rightQ.pop();

        if (lTemp->val != rTemp->val)
            return false;

        if ((lTemp->left == nullptr && rTemp->right != nullptr) || (lTemp->left != nullptr && rTemp->right == nullptr))
            return false;
        else if (lTemp->left != nullptr && rTemp->right != nullptr)
        {
            leftQ.push(lTemp->left);
            rightQ.push(rTemp->right);
        }

        if ((lTemp->right == nullptr && rTemp->left != nullptr) || (lTemp->right != nullptr && rTemp->left == nullptr))
            return false;
        else if (lTemp->right != nullptr && rTemp->left != nullptr)
        {
            leftQ.push(lTemp->right);
            rightQ.push(rTemp->left);
        }
    }

    return true;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "true" : "false") << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
