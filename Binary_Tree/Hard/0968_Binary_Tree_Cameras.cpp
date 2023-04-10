#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

char status(TreeNode* root, int& numOfCameras)
{
    /*
     * status == 'c': a camera is installed in this node
     * status == 'w': no camera is installed in this node but it is watched by neighboring one
     * status == 'u': neither camera is installed here nor the node is watched by other cameras
     * status == 'x': nullptr
     */

    char ls = 'x', rs = 'x';
    if (root->left != nullptr)
        ls = status(root->left, numOfCameras);
    if (root->right != nullptr)
        rs = status(root->right, numOfCameras);

    if (ls == 'u' || rs == 'u')
    {
        numOfCameras++;
        return 'c';
    }
    else if (ls == 'c' || rs == 'c')
        return 'w';
    else
        return 'u';
}

int minCameraCover(TreeNode* root)
{
    int output = 0;
    char ls = 'x', rs = 'x';
    if (root->left != nullptr)
        ls = status(root->left, output);
    if (root->right != nullptr)
        rs = status(root->right, output);

    if (ls == 'u' || rs == 'u' || (ls != 'c' && rs != 'c'))
        return 1 + output;
    else
        return output;
}

int main()
{
    TreeNode* root = new TreeNode();
    root->left = new TreeNode();
    root->left->left = new TreeNode();
    root->left->right = new TreeNode();

    cout << minCameraCover(root) << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}
