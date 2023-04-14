#include <iostream>
using namespace std;

/*bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    while ((n & 1) == 0)
        n >>= 1;

    return (n == 1);
}*/

// No-looping version
bool isPowerOfTwo(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);   // n = 100...0 -> n-1 = 011...1
}

int main()
{
    int n;
    cin >> n;
    cout << (isPowerOfTwo(n) ? "true" : "false") << endl;

    return 0;
}
