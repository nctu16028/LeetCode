#include <iostream>
#include <vector>
#include <stack>
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

vector<int> postorder(Node* root) {
    vector<int> output;
    if (root == nullptr)
        return output;

    stack<Node*> visitOrder;
    visitOrder.push(root);
    while (!visitOrder.empty()) {
        Node* temp = visitOrder.top();
        if (temp->children.empty()) {
            output.push_back(temp->val);
            visitOrder.pop();
        }
        else {
            for (int i = temp->children.size() - 1; i >= 0; i--)
                visitOrder.push(temp->children[i]);
            temp->children.clear();
        }
    }

    return output;
}

int main() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    vector<int> ans = postorder(root);
    cout << "[";
    if (!ans.empty()) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++)
            cout << ", " << ans[i];
    }
    cout << "]" << endl;

    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;

    return 0;
}
