#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node* intersectSubtreeRecursively(Node* subTree1, Node* subTree2) {
    Node* root;

    if (subTree1->isLeaf && subTree2->isLeaf) {
        root = new Node(subTree1->val || subTree2->val, true);
    }
    else if (subTree1->isLeaf) {
        if (subTree1->val == 1)
            root = new Node(1, true);
        else {
            root = new Node(0, false);
            root->topLeft = subTree2->topLeft;
            root->topRight = subTree2->topRight;
            root->bottomLeft = subTree2->bottomLeft;
            root->bottomRight = subTree2->bottomRight;
            subTree2->topLeft = nullptr;
            subTree2->topRight = nullptr;
            subTree2->bottomLeft = nullptr;
            subTree2->bottomRight = nullptr;
        }
    }
    else if (subTree2->isLeaf) {
        if (subTree2->val == 1)
            root = new Node(1, true);
        else {
            root = new Node(0, false);
            root->topLeft = subTree1->topLeft;
            root->topRight = subTree1->topRight;
            root->bottomLeft = subTree1->bottomLeft;
            root->bottomRight = subTree1->bottomRight;
            subTree1->topLeft = nullptr;
            subTree1->topRight = nullptr;
            subTree1->bottomLeft = nullptr;
            subTree1->bottomRight = nullptr;
        }
    }
    else {
        root = new Node(0, false);
        root->topLeft = intersectSubtreeRecursively(subTree1->topLeft, subTree2->topLeft);
        root->topRight = intersectSubtreeRecursively(subTree1->topRight, subTree2->topRight);
        root->bottomLeft = intersectSubtreeRecursively(subTree1->bottomLeft, subTree2->bottomLeft);
        root->bottomRight = intersectSubtreeRecursively(subTree1->bottomRight, subTree2->bottomRight);
        if (root->topLeft->isLeaf && root->topRight->isLeaf && root->bottomLeft->isLeaf && root->bottomRight->isLeaf &&
            root->topLeft->val == root->topRight->val && root->topLeft->val == root->bottomLeft->val && root->topLeft->val == root->bottomRight->val) {
            root->val = root->topLeft->val;
            root->isLeaf = true;
            delete root->topLeft;
            delete root->topRight;
            delete root->bottomLeft;
            delete root->bottomRight;
            root->topLeft = nullptr;
            root->topRight = nullptr;
            root->bottomLeft = nullptr;
            root->bottomRight = nullptr;
        }
    }

    return root;
}

Node* intersect(Node* quadTree1, Node* quadTree2) {
    return intersectSubtreeRecursively(quadTree1, quadTree2);
}

void deleteNodes(Node* root) {
    if (!(root->isLeaf)) {
        deleteNodes(root->topLeft);
        deleteNodes(root->topRight);
        deleteNodes(root->bottomLeft);
        deleteNodes(root->bottomRight);
    }
    delete root;
}

int main() {
    Node* quadTree1 = new Node(1, false);
    quadTree1->topLeft = new Node(1, true);
    quadTree1->topRight = new Node(1, true);
    quadTree1->bottomLeft = new Node(0, true);
    quadTree1->bottomRight = new Node(0, true);

    Node* quadTree2 = new Node(1, false);
    quadTree2->topLeft = new Node(1, true);
    quadTree2->topRight = new Node(1, false);
    quadTree2->bottomLeft = new Node(1, true);
    quadTree2->bottomRight = new Node(0, true);
    quadTree2->topRight->topLeft = new Node(0, true);
    quadTree2->topRight->topRight = new Node(0, true);
    quadTree2->topRight->bottomLeft = new Node(1, true);
    quadTree2->topRight->bottomRight = new Node(1, true);

    Node* ans = intersect(quadTree1, quadTree2);
    deleteNodes(quadTree1);
    deleteNodes(quadTree2);
    deleteNodes(ans);

    return 0;
}
