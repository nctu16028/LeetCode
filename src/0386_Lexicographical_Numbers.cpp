#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int curr, vector<int>& nums) {
    for (int i = 0; i <= 9; i++) {
        if (curr + i >= 1 && curr + i <= n) {
            nums.push_back(curr + i);
            dfs(n, 10 * (curr + i), nums);
        }
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> output;
    dfs(n, 0, output);
    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int> ans = lexicalOrder(n);
    cout << "[" << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ", " << ans[i];
    cout << "]" << endl;

    return 0;
}
