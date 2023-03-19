#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    long long int x_ori = x;
    long long int x_rev = 0;
    while (x > 0)
    {
        x_rev = x_rev * 10 + x % 10;
        x /= 10;
    }

    return (x_ori == x_rev);
}

int main()
{
    int x;
    cin >> x;
    cout << (isPalindrome(x) ? "true" : "false") << endl;

    return 0;
}
