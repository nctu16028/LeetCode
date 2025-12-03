#include <iostream>
#include <vector>
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

vector<int> largestValues(TreeNode* root) {
    vector<int> output;
    queue<pair<int, TreeNode*>> toVisit;
    int depth = 0;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        if (toVisit.front().first != depth) {
            output.push_back(toVisit.front().second->val);
            depth = toVisit.front().first;
        }
        TreeNode* curr = toVisit.front().second;
        toVisit.pop();
        if (curr->val > output.back())
            output.back() = curr->val;
        if (curr->left != nullptr)
            toVisit.push(make_pair(depth + 1, curr->left));
        if (curr->right != nullptr)
            toVisit.push(make_pair(depth + 1, curr->right));
    }

    return output;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    vector<int> ans = largestValues(root);
    if (ans.empty())
        cout << "[]" << endl;
    else {
        cout << "[" << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
        cout << "]" << endl;
    }

    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
