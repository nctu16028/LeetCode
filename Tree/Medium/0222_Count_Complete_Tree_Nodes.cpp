#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countNodes(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    // Find the index of the rightmost node, assuming each node is indexed in level-order.
    int output = 1;
    TreeNode* curr = root;
    while (curr->right != nullptr)
    {
        output = output * 2 + 1;
        curr = curr->right;
    }

    // Perform right-to-left DFS. The first leaf index larger than the rightmost index is the number of nodes.
    stack<TreeNode*> pathToVisit;
    stack<int> numTracked;
    pathToVisit.push(root);
    numTracked.push(1);
    while (!pathToVisit.empty())
    {
        TreeNode* currNode = pathToVisit.top();
        int currNum = numTracked.top();
        pathToVisit.pop();
        numTracked.pop();

        if (currNum > output)
            return currNum;

        if (currNode->left != nullptr)
        {
            pathToVisit.push(currNode->left);
            numTracked.push(currNum * 2);
        }
        if (currNode->right != nullptr)
        {
            pathToVisit.push(currNode->right);
            numTracked.push(currNum * 2 + 1);
        }
    }

    // If there is no index larger than the rightmost one, then it is just the answer.
    return output;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << countNodes(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
