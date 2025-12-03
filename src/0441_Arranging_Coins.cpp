#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    int left = 1, right = 65535;    // initial range = [1, (2^16)-1]
    if (right * ((right + 1) / 2) <= n)
        return right;

    while (left + 1 < right) {
        int mid = (left + right) / 2;
        int key = (mid % 2) ? (mid * ((mid + 1) / 2)) : (mid / 2 * (mid + 1));
        if (key > n)
            right = mid;
        else if (key < n)
            left = mid;
        else
            return mid;
    }

    return left;
}

int main() {
    int n;
    cin >> n;
    cout << arrangeCoins(n) << endl;

    return 0;
}
