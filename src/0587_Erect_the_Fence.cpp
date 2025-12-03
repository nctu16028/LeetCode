#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cross_product(const vector<int>& origin, const vector<int>& pi, const vector<int>& pj) {
    return (pi[0] - origin[0]) * (pj[1] - origin[1]) - (pi[1] - origin[1]) * (pj[0] - origin[0]);
}

int squared_distance(const vector<int>& origin, const vector<int>& p) {
    return (p[0] - origin[0]) * (p[0] - origin[0]) + (p[1] - origin[1]) * (p[1] - origin[1]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n = trees.size();
    if (n <= 3)
        return trees;

    // Pick out the leftmost bottom point
    int p0_idx = 0, p0_y = trees[0][1], p0_x = trees[0][0];
    for (int i = 1; i < n; i++) {
        if (trees[i][1] < p0_y || (trees[i][1] == p0_y && trees[i][0] < p0_x)) {
            p0_idx = i;
            p0_y = trees[i][1];
            p0_x = trees[i][0];
        }
    }
    swap(trees[0], trees[p0_idx]);

    // Sort the other points by polar angle
    struct angleLess {
        vector<int> p0;
        angleLess(vector<int> p0) : p0(p0) {}
        bool operator()(vector<int> pi, vector<int> pj) const {
            int cross_prod = cross_product(p0, pi, pj);
            if (cross_prod == 0)    // colinear
                return squared_distance(p0, pi) < squared_distance(p0, pj);
            return cross_prod > 0;  // pi is clockwise from pj (pi < pj)
        }
    };
    sort(trees.begin() + 1, trees.end(), angleLess(trees[0]));

    // Graham's scan
    vector<vector<int>> convex_hull(trees.begin(), trees.begin() + 3);
    for (int i = 3; i < n; i++) {
        while (convex_hull.size() >= 2 && cross_product(convex_hull[convex_hull.size() - 2], convex_hull[convex_hull.size() - 1], trees[i]) < 0)
            convex_hull.pop_back();
        convex_hull.push_back(trees[i]);
    }

    // Make up the points colinear to CH[0] and CH[last]
    int curr = n - 2;
    while (trees[0][1] != trees[n - 1][1] && cross_product(trees[0], trees[n - 1], trees[curr]) == 0)
        convex_hull.push_back(trees[curr--]);

    return convex_hull;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> trees(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> trees[i][0] >> trees[i][1];

    vector<vector<int>> ans = outerTrees(trees);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;

    return 0;
}
