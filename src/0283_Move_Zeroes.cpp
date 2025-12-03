#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int toPlace = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0)
            nums[toPlace++] = nums[i];
    }
    while (toPlace < nums.size())
        nums[toPlace++] = 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    moveZeroes(nums);
    cout << "[" << nums[0];
    for (int i = 1; i < n; i++)
        cout << ", " << nums[i];
    cout << "]" << endl;

    return 0;
}
