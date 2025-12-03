#include <iostream>
#include <vector>
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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> output;
    if (root == nullptr)
        return output;

    stack<TreeNode*> toVisit;
    toVisit.push(root);

    while (!toVisit.empty()) {
        TreeNode* temp = toVisit.top();
        toVisit.pop();
        output.push_back(temp->val);

        if (temp->right != nullptr)
            toVisit.push(temp->right);
        if (temp->left != nullptr)
            toVisit.push(temp->left);
    }

    return output;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    vector<int> ans = preorderTraversal(root);
    cout << "[";
    if (ans.size() > 0) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    delete root->right->right->left;
    delete root->right->right;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
