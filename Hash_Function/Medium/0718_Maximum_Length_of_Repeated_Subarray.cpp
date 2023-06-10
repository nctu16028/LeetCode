#include <iostream>
#include <vector>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size(), n = nums2.size();
    //vector<vector<int>> dpTable(m, vector<int>(n, 0));  // dpTable[i][j] is the longest common prefix of nums1[i:] and nums2[j:]
    int* dpCurr = new int[n];
    int* dpPrev = new int[n];
    int output = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dpCurr[j] = (nums1[i] == nums2[j]);
            if (i != m - 1 && j != n - 1 && nums1[i + 1] == nums2[j + 1])
                dpCurr[j] += dpPrev[j + 1];
            output = max(output, dpCurr[j]);
        }
        swap(dpCurr, dpPrev);
    }
    delete [] dpCurr;
    delete [] dpPrev;

    return output;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m);
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    vector<int> nums2(n);
    for (int j = 0; j < n; j++)
        cin >> nums2[j];

    cout << findLength(nums1, nums2) << endl;

    return 0;
}
