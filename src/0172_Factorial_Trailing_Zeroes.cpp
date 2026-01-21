#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    // If the prime factorization of n! contains 2^a and 5^b,
    // the number of trailing zeroes in n! is min(a, b) = b.
    // b = (n / 5) + (n / 5^2) + (n / 5^3) + ...
    int b = 0;
    for (int d = 5; d <= n; d *= 5)
        b += (n / d);

    return b;
}

int main() {
    int n;
    cin >> n;
    cout << trailingZeroes(n) << endl;

    return 0;
}