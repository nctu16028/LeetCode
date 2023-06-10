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

void recursiveHelper(string& s, TreeNode* root)
{
    if (root == nullptr)
        s += ".";
    else
    {
        s += (to_string(root->val) + "|");
        recursiveHelper(s, root->left);
        s += ("|" + to_string(root->val) + "|");
        recursiveHelper(s, root->right);
        s += ("|" + to_string(root->val));
    }
}

string stringHash(TreeNode* root)
{
    string output = "";
    recursiveHelper(output, root);
    return output;
}

bool stringMatching(const string& text, const string& pattern)
{
    if (pattern.length() > text.length())
        return false;

    // Build the prefix function of pattern
    vector<int> pf(pattern.length(), -1);
    for (int i = 1, j = -1; i < pattern.length(); i++)
    {
        while (j >= 0 && pattern[j + 1] != pattern[i])
            j = pf[j];
        if (pattern[j + 1] == pattern[i])
            j++;
        pf[i] = j;
    }

    // Search for the pattern
    for (int i = 0, j = -1; i < text.length(); i++)
    {
        while (j >= 0 && pattern[j + 1] != text[i])
            j = pf[j];
        if (pattern[j + 1] == text[i])
            j++;
        if (j == pattern.length() - 1)
            return true;
    }

    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    string rootStr = stringHash(root);
    string subRootStr = stringHash(subRoot);
    return stringMatching(rootStr, subRootStr);
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    cout << (isSubtree(root, subRoot) ? "true" : "false") << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    delete subRoot->left;
    delete subRoot->right;
    delete subRoot;

    return 0;
}
