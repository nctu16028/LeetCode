#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class SegmentTree {
public:
    SegmentTree(int n) {
        arrSize = n;
        int temp = 1;
        while (temp < arrSize)
            temp *= 2;
        segSumTable.resize(temp * 2 - 1);   // temp is the smallest power of 2 that is larger or equal to arrSize
        fillTable(0, 0, arrSize - 1);
    }
    
    void update(int index, int val) {
        updateRecursive(0, 0, arrSize - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryRecursive(0, 0, arrSize - 1, left, right);
    }

private:
    int arrSize;
    vector<int> segSumTable;

    void fillTable(int i, int rangeHead, int rangeTail)
    {
        if (rangeHead == rangeTail)
        {
            segSumTable[i] = 1;
            return;
        }

        int mid = (rangeHead + rangeTail) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        fillTable(leftChild, rangeHead, mid);       // fill the left children (i -> 2*i+1)
        fillTable(rightChild, mid + 1, rangeTail);  // fill the right children (i -> 2*i+2)
        segSumTable[i] = segSumTable[leftChild] + segSumTable[rightChild];
    }

    int updateRecursive(int i, int rangeHead, int rangeTail, int queryIdx, int newVal)
    {
        if (rangeHead == rangeTail)
        {
            int diff = newVal - segSumTable[i];
            segSumTable[i] = newVal;
            return diff;
        }

        int mid = (rangeHead + rangeTail) / 2;
        int diff;
        if (queryIdx >= rangeHead && queryIdx <= mid)
            diff = updateRecursive(2 * i + 1, rangeHead, mid, queryIdx, newVal);
        else
            diff = updateRecursive(2 * i + 2, mid + 1, rangeTail, queryIdx, newVal);
        segSumTable[i] += diff;

        return diff;
    }

    int queryRecursive(int i, int rangeHead, int rangeTail, int queryHead, int queryTail)
    {
        if (queryTail < rangeHead || rangeTail < queryHead)     // the range of this segment is totally out of the query range
            return 0;

        if (queryHead <= rangeHead && rangeTail <= queryTail)   // the range of this segment is totally contained in the query range
            return segSumTable[i];

        int mid = (rangeHead + rangeTail) / 2;
        return queryRecursive(2 * i + 1, rangeHead, mid, queryHead, queryTail) + 
               queryRecursive(2 * i + 2, mid + 1, rangeTail, queryHead, queryTail);
    }
};

int countRangeSum(vector<int>& nums, int lower, int upper)
{
    int n = nums.size();
    vector<long long int> prefixSum(n + 1, 0);  // prefixSum[i] = sum(0, i-1) = sum of subarray nums[0..i] (i excluded)
    unordered_map<long long int, int> offset;
    offset.insert({prefixSum[0], 0});
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        offset.insert({prefixSum[i], 0});
    }

    vector<long long int> sortedPFS(prefixSum.begin(), prefixSum.end());
    sort(sortedPFS.begin(), sortedPFS.end());
    SegmentTree st(n + 1);  // this segment tree tells how many PFS are available between some interval of sortedPFS

    // The goal is to find the number of sum(i, j) such that lower <= sum(i, j) <= upper, which is the same as
    // the sum, w.r.t. each i, of the number of sum(0, j) such that lower + sum(0, i-1) <= sum(0, j) <= upper + sum(0, i-1)
    int output = 0;
    for (int i = 0; i < n; i++)
    {
        // Mark sum(0, i-1) as unavailable
        int idx = lower_bound(sortedPFS.begin(), sortedPFS.end(), prefixSum[i]) - sortedPFS.begin();
        st.update(idx + offset[prefixSum[i]], 0);
        offset[prefixSum[i]]++;

        // Count the number of available sum(0, j) between "lower + sum(0, i-1)" and "upper + sum(0, i-1)"
        int lowerIdx = lower_bound(sortedPFS.begin(), sortedPFS.end(), lower + prefixSum[i]) - sortedPFS.begin();
        int upperIdx = upper_bound(sortedPFS.begin(), sortedPFS.end(), upper + prefixSum[i]) - sortedPFS.begin() - 1;
        output += st.sumRange(lowerIdx, upperIdx);
    }

    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int lower, upper;
    cin >> lower >> upper;
    cout << countRangeSum(nums, lower, upper) << endl;

    return 0;
}
