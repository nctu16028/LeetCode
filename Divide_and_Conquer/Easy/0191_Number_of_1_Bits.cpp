#include <iostream>
#include <string>
using namespace std;

int reverseHelper(uint32_t n, uint32_t maskLen)
{
    if (maskLen == 0)
        return n;

    uint32_t upper = n >> maskLen;
    uint32_t lower = n & ((1 << maskLen) - 1);
    int numUpper = reverseHelper(upper, maskLen / 2);
    int numLower = reverseHelper(lower, maskLen / 2);
    return numUpper + numLower;
}

int hammingWeight(uint32_t n)
{
    return reverseHelper(n, 16);
}

int main()
{
    string binStr;
    cin >> binStr;
    uint32_t n = stoul(binStr, nullptr, 2);
    cout << hammingWeight(n) << endl;

    return 0;
}
