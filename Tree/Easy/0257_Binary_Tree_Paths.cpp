#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void buildPath(vector<string>& paths, const string& path, TreeNode* root)
{
    if (root == nullptr)
        return;

    string newPath = path + "->" + to_string(root->val);
    buildPath(paths, newPath, root->left);
    buildPath(paths, newPath, root->right);
    if (root->left == nullptr && root->right == nullptr)
        paths.push_back(newPath);
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> output;
    string path = to_string(root->val);
    buildPath(output, path, root->left);
    buildPath(output, path, root->right);
    if (root->left == nullptr && root->right == nullptr)
        output.push_back(path);

    return output;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> ans = binaryTreePaths(root);
    cout << "[\"" << ans[0] << "\"";
    for (int i = 1; i < ans.size(); i++)
        cout << ", \"" << ans[i] << "\"";
    cout << "]" << endl;

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
