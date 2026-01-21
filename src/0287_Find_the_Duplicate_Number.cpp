#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    /*
     * We treat the input array as a linked list where
     * each entry nums[i] is a list node with id = i and next = nums[i]. (i = 0, 1, ..., n)
     *
     * The duplicate number must be a node pointed by at least two "next" pointers,
     * and it will be the entrance of a cycle. (The cycle may contain the duplicate-number node alone.)
     *
     * Thus, the algorithm to solve this problem is the same as [142. Linked List Cycle II].
     * (Reference: https://cp-algorithms.com/others/tortoise_and_hare.html)
     */

    // Step 1: Use two pointers method to reach one of the nodes in the cycle
    int slow = 0, fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Step 2: Find the entrance node of the cycle
    int entrance = 0;
    while (entrance != slow) {
        entrance = nums[entrance];
        slow = nums[slow];
    }

    return entrance;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> nums[i];
    cout << findDuplicate(nums) << endl;

    return 0;
}