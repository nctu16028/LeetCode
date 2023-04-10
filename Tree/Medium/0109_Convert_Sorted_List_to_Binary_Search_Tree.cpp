#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedListToBST_helper(ListNode* head, int len)
{
    if (len == 0)
        return nullptr;
    else if (len == 1)
    {
        TreeNode* newRoot = new TreeNode(head->val);
        delete head;
        return newRoot;
    }

    int mid = len / 2;
    ListNode* midNode = head;
    ListNode* prevMid = nullptr;
    for (int i = 0; i < mid; i++)
    {
        prevMid = midNode;
        midNode = midNode->next;
    }
    ListNode* leftHead = head;
    ListNode* rightHead = midNode->next;
    prevMid->next = nullptr;

    TreeNode* newRoot = new TreeNode(midNode->val);
    newRoot->left = sortedListToBST_helper(leftHead, mid);
    newRoot->right = sortedListToBST_helper(rightHead, len - mid - 1);
    delete midNode;

    return newRoot;
}

TreeNode* sortedListToBST(ListNode* head)
{
    int len = 0;
    for (ListNode* curr = head; curr != nullptr; curr = curr->next)
        len++;

    return sortedListToBST_helper(head, len);
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

    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = new ListNode();
            curr = head;
        }
        else
        {
            curr->next = new ListNode();
            curr = curr->next;
        }
        cin >> curr->val;
    }

    TreeNode* ans = sortedListToBST(head);
    printAndDeleteNode(ans);
    cout << endl;

    return 0;
}
