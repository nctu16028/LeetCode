#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    vector<int> order;
    int curr;

    void inOrderTraversal(TreeNode* root) {
        if (root == nullptr)
            return;
        inOrderTraversal(root->left);
        order.push_back(root->val);
        inOrderTraversal(root->right);
    }

    BSTIterator(TreeNode* root) {
        inOrderTraversal(root);
        curr = 0;
    }
    
    int next() {
        int output = order[curr];
        curr++;
        return output;
    }
    
    bool hasNext() {
        return (curr < order.size());
    }
};

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* bSTIterator = new BSTIterator(root);
    cout << bSTIterator->next() << endl;                            // return 3
    cout << bSTIterator->next() << endl;                            // return 7
    cout << (bSTIterator->hasNext() ? "true" : "false") << endl;    // return True
    cout << bSTIterator->next() << endl;                            // return 9
    cout << (bSTIterator->hasNext() ? "true" : "false") << endl;    // return True
    cout << bSTIterator->next() << endl;                            // return 15
    cout << (bSTIterator->hasNext() ? "true" : "false") << endl;    // return True
    cout << bSTIterator->next() << endl;                            // return 20
    cout << (bSTIterator->hasNext() ? "true" : "false") << endl;    // return False

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
