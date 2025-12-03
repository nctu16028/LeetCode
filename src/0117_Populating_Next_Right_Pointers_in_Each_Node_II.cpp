#include <iostream>
#include <queue>
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

Node* connect(Node* root) {
    queue<pair<int, Node*>> toVisit;
    int depth = 0;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        depth = toVisit.front().first;
        Node* curr = toVisit.front().second;
        toVisit.pop();

        if (!toVisit.empty() && toVisit.front().first == depth)
            curr->next = toVisit.front().second;
        if (curr->left != nullptr)
            toVisit.push(make_pair(depth + 1, curr->left));
        if (curr->right != nullptr)
            toVisit.push(make_pair(depth + 1, curr->right));
    }

    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
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
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
