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

int findBottomLeftValue(TreeNode* root) {
    queue<pair<int, TreeNode*>> toVisit;
    int depth = 0, output;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        if (toVisit.front().first != depth) {
            depth = toVisit.front().first;
            output = toVisit.front().second->val;
        }
        TreeNode* curr = toVisit.front().second;
        toVisit.pop();
        if (curr->left != nullptr)
            toVisit.push(make_pair(depth + 1, curr->left));
        if (curr->right != nullptr)
            toVisit.push(make_pair(depth + 1, curr->right));
    }

    return output;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << findBottomLeftValue(root) << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
