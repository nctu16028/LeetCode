#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        arrSize = nums.size();
        int temp = 1;
        while (temp < arrSize)
            temp *= 2;
        segSumTable.resize(temp * 2 - 1);   // temp is the smallest power of 2 that is larger or equal to arrSize
        fillTable(0, nums, 0, arrSize - 1);
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

    void fillTable(int i, const vector<int>& nums, int rangeHead, int rangeTail)
    {
        if (rangeHead == rangeTail)
        {
            segSumTable[i] = nums[rangeHead];
            return;
        }

        int mid = (rangeHead + rangeTail) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        fillTable(leftChild, nums, rangeHead, mid);         // fill the left children (i -> 2*i+1)
        fillTable(rightChild, nums, mid + 1, rangeTail);    // fill the right children (i -> 2*i+2)
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

int main()
{
    vector<int> nums({1, 3, 5});
    NumArray* numArray = new NumArray(nums);
    cout << numArray->sumRange(0, 2) << endl;
    numArray->update(1, 2);
    cout << numArray->sumRange(0, 2) << endl;
    delete numArray;

    return 0;
}
