#include <iostream>
#include <vector>
using namespace std;

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n));  // dp[i][j] is the max dot product of nums1[0:i+1] and nums2[0:j+1]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                dp[0][0] = nums1[0] * nums2[0];
            else if (i == 0)
                dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
            else if (j == 0)
                dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
            else
                dp[i][j] = max(max(dp[i][j - 1], dp[i - 1][j]), max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j]);
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m);
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    vector<int> nums2(n);
    for (int j = 0; j < n; j++)
        cin >> nums2[j];

    cout << maxDotProduct(nums1, nums2) << endl;

    return 0;
}