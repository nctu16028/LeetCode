#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int output = 0;
    int diff = right - left;
    for (int i = 0; i < 31; i++)
    {
        int mask = (1 << i);    // the mask of the i-th bit (0-indexed, right-to-left)
        if (diff < mask && (left & mask) != 0 && (right & mask) != 0)   // if the i-th bit is not 0 for all numbers in [left, right]
            output |= mask;     // then the i-th bit of output is 1 for sure
    }

    return output;
}

int main()
{
    int left, right;
    cin >> left >> right;
    cout << rangeBitwiseAnd(left, right) << endl;

    return 0;
}
