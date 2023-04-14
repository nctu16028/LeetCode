#include <iostream>
#include <string>
using namespace std;

uint32_t reverseHelper(uint32_t n, uint32_t maskLen)
{
    if (maskLen == 1)
        return ((n & 1) << 1) + (n >> 1);   // swap the two bits

    uint32_t upper = n >> maskLen;
    uint32_t lower = n & ((1 << maskLen) - 1);
    upper = reverseHelper(upper, maskLen / 2);
    lower = reverseHelper(lower, maskLen / 2);

    return (lower << maskLen) + upper;
}

uint32_t reverseBits(uint32_t n)
{
    return reverseHelper(n, 16);
}

int main()
{
    string binStr;
    cin >> binStr;
    uint32_t n = stoul(binStr, nullptr, 2);
    cout << reverseBits(n) << endl;

    return 0;
}
