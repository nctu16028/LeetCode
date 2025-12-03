#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void postOrderTraversal(TreeNode* root, unordered_map<int, int>& freq) {
    if (root->left != nullptr) {
        postOrderTraversal(root->left, freq);
        root->val += root->left->val;
    }
    if (root->right != nullptr) {
        postOrderTraversal(root->right, freq);
        root->val += root->right->val;
    }

    if (freq.find(root->val) == freq.end())
        freq.insert(make_pair(root->val, 0));
    freq[root->val]++;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> freq;
    postOrderTraversal(root, freq);

    vector<int> output;
    int maxFreq = 0;
    for (const auto& item : freq) {
        if (item.second > maxFreq) {
            maxFreq = item.second;
            output.clear();
            output.push_back(item.first);
        }
        else if (item.second == maxFreq)
            output.push_back(item.first);
    }

    return output;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    vector<int> ans = findFrequentTreeSum(root);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
