#include <iostream>
#include <vector>
using namespace std;

int mergeTwoArray(vector<int>& nums, int head, int mid, int tail)
{
    vector<int> leftHalf(mid - head + 1);
    vector<int> rightHalf(tail - mid);
    for (int i = head; i <= mid; i++)
        leftHalf[i - head] = nums[i];
    for (int i = mid + 1; i <= tail; i++)
        rightHalf[i - mid - 1] = nums[i];

    // Calculate the number of reverse pairs before merging the arrays
    int numReversePairs = 0;
    int lIdx = 0, rIdx = 0;
    while (lIdx < leftHalf.size())
    {
        if (rIdx < rightHalf.size() && (long long int)leftHalf[lIdx] > 2 * (long long int)rightHalf[rIdx])
            rIdx++;
        else
        {
            numReversePairs += rIdx;
            lIdx++;
        }
    }

    // Merge the arrays
    lIdx = 0, rIdx = 0;
    int i = head;
    while (lIdx < leftHalf.size() && rIdx < rightHalf.size())
    {
        if (leftHalf[lIdx] <= rightHalf[rIdx])
            nums[i++] = leftHalf[lIdx++];
        else
            nums[i++] = rightHalf[rIdx++];
    }
    while (lIdx < leftHalf.size())
        nums[i++] = leftHalf[lIdx++];
    while (rIdx < rightHalf.size())
        nums[i++] = rightHalf[rIdx++];

    return numReversePairs;
}

int mergeSort(vector<int>& nums, int head, int tail)
{
    if (head >= tail)
        return 0;

    int mid = (head + tail) / 2;
    int numLeft = mergeSort(nums, head, mid);
    int numRight = mergeSort(nums, mid + 1, tail);
    int numCross = mergeTwoArray(nums, head, mid, tail);
    return numLeft + numRight + numCross;
}

int reversePairs(vector<int>& nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << reversePairs(nums) << endl;

    return 0;
}
