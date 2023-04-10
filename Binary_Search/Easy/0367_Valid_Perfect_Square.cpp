#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
    long long int left = 1, right = num / 2;
    if (num == 1 || num == right * right)
        return true;

    while (left + 1 < right)
    {
        long long int mid = (left + right) / 2;
        if (num > mid * mid)
            left = mid;
        else if (num < mid * mid)
            right = mid;
        else
            return true;
    }

    return false;
}

int main()
{
    int num;
    cin >> num;
    cout << (isPerfectSquare(num) ? "true" : "false") << endl;

    return 0;
}
