#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return prefixSum[right];
        else
            return prefixSum[right] - prefixSum[left - 1];
    }
};

int main()
{
    vector<int> nums({-2, 0, 3, -5, 2, -1});
    NumArray* numArray = new NumArray(nums);
    cout << numArray->sumRange(0, 2) << endl;
    cout << numArray->sumRange(2, 5) << endl;
    cout << numArray->sumRange(0, 5) << endl;

    return 0;
}
