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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> output;
    queue<pair<int, Node*>> toVisit;
    int depth = 0;
    if (root != nullptr)
        toVisit.push(make_pair(depth + 1, root));

    while (!toVisit.empty()) {
        if (toVisit.front().first != depth) {
            output.push_back(vector<int>());
            depth = toVisit.front().first;
        }
        Node* curr = toVisit.front().second;
        toVisit.pop();
        output.back().push_back(curr->val);
        for (int i = 0; i < curr->children.size(); i++)
            toVisit.push(make_pair(depth + 1, curr->children[i]));
    }

    return output;
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

    vector<vector<int>> ans = levelOrder(root);
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

    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;

    return 0;
}
