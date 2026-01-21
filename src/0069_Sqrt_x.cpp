#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x == 0)
        return 0;

    if (x >= 46340 * 46340)
        return 46340;

    int left = 0, right = 46340;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (x >= mid * mid && x < (mid + 1) * (mid + 1))
            return mid;

        if (x < mid * mid)
            right = mid;
        else
            left = mid;
    }

    return left;
}

int main() {
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;

    return 0;
}