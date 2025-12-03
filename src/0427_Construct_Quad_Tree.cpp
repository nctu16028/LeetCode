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

Node* constructRecursively(const vector<vector<int>>& grid, int top, int bottom, int left, int right) {
    Node* root;

    if (top == bottom && left == right)
        root = new Node(grid[top][left], true);
    else {
        int midRow = (top + bottom) / 2;
        int midCol = (left + right) / 2;
        Node* topLeftSubtree = constructRecursively(grid, top, midRow, left, midCol);
        Node* topRightSubtree = constructRecursively(grid, top, midRow, midCol + 1, right);
        Node* bottomLeftSubtree = constructRecursively(grid, midRow + 1, bottom, left, midCol);
        Node* bottomRightSubtree = constructRecursively(grid, midRow + 1, bottom, midCol + 1, right);
        if (topLeftSubtree->isLeaf && topRightSubtree->isLeaf && bottomLeftSubtree->isLeaf && bottomRightSubtree->isLeaf &&
            topLeftSubtree->val == topRightSubtree->val && topLeftSubtree->val == bottomLeftSubtree->val && topLeftSubtree->val == bottomRightSubtree->val) {
            delete topLeftSubtree;
            delete topRightSubtree;
            delete bottomLeftSubtree;
            delete bottomRightSubtree;
            root = new Node(grid[top][left], true);
        }
        else
            root = new Node(grid[top][left], false, topLeftSubtree, topRightSubtree, bottomLeftSubtree, bottomRightSubtree);
    }

    return root;
}

Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    return constructRecursively(grid, 0, n - 1, 0, n - 1);
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
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    Node* ans = construct(grid);
    deleteNodes(ans);

    return 0;
}
