#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

void connectSubtree(Node* root)
{
    if (root == nullptr)
        return;

    connectSubtree(root->left);
    connectSubtree(root->right);

    Node* leftTail = root->left;
    Node* rightHead = root->right;
    while (leftTail != nullptr)
    {
        leftTail->next = rightHead;
        leftTail = leftTail->right;
        rightHead = rightHead->left;
    }
}

Node* connect(Node* root)
{
    connectSubtree(root);
    return root;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root = connect(root);

    cout << "[";
    Node* currLevelHead = root;
    while (currLevelHead != nullptr)
    {
        Node* curr = currLevelHead;
        while (curr != nullptr)
        {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << "#, ";
        currLevelHead = currLevelHead->left;
    }
    if (root != nullptr)
        cout << "\b\b";
    cout << "]" << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
