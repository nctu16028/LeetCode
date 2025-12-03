#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> output;
    queue<pair<int, TreeNode*>> toVisit;
    int depth = 0;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        if (toVisit.front().first != depth) {
            output.push_back(vector<int>());
            depth = toVisit.front().first;
        }
        TreeNode* curr = toVisit.front().second;
        toVisit.pop();
        output.back().push_back(curr->val);
        if (curr->left != nullptr)
            toVisit.push(make_pair(depth + 1, curr->left));
        if (curr->right != nullptr)
            toVisit.push(make_pair(depth + 1, curr->right));
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrderBottom(root);
    if (ans.empty())
        cout << "[]" << endl;
    else {
        cout << "[[" << ans[0][0];
        for (int j = 1; j < ans[0].size(); j++)
            cout << ", " << ans[0][j];
        cout << "]";
        for (int i = 1; i < ans.size(); i++) {
            cout << ", [" << ans[i][0];
            for (int j = 1; j < ans[i].size(); j++)
                cout << ", " << ans[i][j];
            cout << "]";
        }
        cout << "]" << endl;
    }

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
