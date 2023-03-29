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

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;

    queue<TreeNode*> pQ, qQ;
    pQ.push(p);
    qQ.push(q);

    while (!pQ.empty())
    {
        TreeNode* pTemp = pQ.front();
        TreeNode* qTemp = qQ.front();
        pQ.pop();
        qQ.pop();

        if (pTemp->val != qTemp->val)
            return false;

        if ((pTemp->left == nullptr && qTemp->left != nullptr) || (pTemp->left != nullptr && qTemp->left == nullptr))
            return false;
        else if (pTemp->left != nullptr && qTemp->left != nullptr)
        {
            pQ.push(pTemp->left);
            qQ.push(qTemp->left);
        }

        if ((pTemp->right == nullptr && qTemp->right != nullptr) || (pTemp->right != nullptr && qTemp->right == nullptr))
            return false;
        else if (pTemp->right != nullptr && qTemp->right != nullptr)
        {
            pQ.push(pTemp->right);
            qQ.push(qTemp->right);
        }
    }

    return true;
}

int main()
{
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << (isSameTree(p, q) ? "true" : "false") << endl;

    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
