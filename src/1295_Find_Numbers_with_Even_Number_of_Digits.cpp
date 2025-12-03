#include <iostream>
#include <vector>
using namespace std;

int findNumbers(vector<int>& nums) {
    int counter = 0;
    for (const auto &num : nums) {
        if (num < 10)
            counter += 0;
        else if (num < 100)
            counter++;
        else if (num < 1000)
            counter += 0;
        else if (num < 10000)
            counter++;
        else if (num < 100000)
            counter += 0;
        else
            counter++;
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << findNumbers(nums) << endl;

    return 0;
}
