#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int idx1 = 0, idx2 = 0;
    for (; idx1 < m + n && idx2 < n; idx1++)
    {
        if (nums2[idx2] < nums1[idx1])
        {
            nums1.insert(nums1.begin() + idx1, nums2[idx2]);
            nums1.pop_back();   // remove one zero from the back
            idx2++;
        }
    }

    while (idx2 < n)
    {
        nums1[m + idx2] = nums2[idx2];
        idx2++;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n, 0);
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    vector<int> nums2(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    merge(nums1, m, nums2, n);
    cout << "[" << nums1[0];
    for (int i = 1; i < m + n; i++)
        cout << ", " << nums1[i];
    cout << "]" << endl;

    return 0;
}
