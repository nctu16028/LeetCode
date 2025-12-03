#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) {
    queue<pair<int, Node*>> toVisit;
    int depth = 0;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        depth = toVisit.front().first;
        Node* curr = toVisit.front().second;
        toVisit.pop();
        for (int i = 0; i < curr->children.size(); i++)
            toVisit.push(make_pair(depth + 1, curr->children[i]));
    }

    return depth;
}

int main() {
    Node* root = new Node(1);
    Node* temp = new Node(3);
    root->children.push_back(temp);
    temp = new Node(2);
    root->children.push_back(temp);
    temp = new Node(4);
    root->children.push_back(temp);
    temp = new Node(5);
    root->children[0]->children.push_back(temp);
    temp = new Node(6);
    root->children[0]->children.push_back(temp);

    cout << maxDepth(root) << endl;

    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;

    return 0;
}
