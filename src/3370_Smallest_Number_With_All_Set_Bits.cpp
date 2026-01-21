#include <iostream>
using namespace std;

int smallestNumber(int n) {
    // Bit smearing
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);

    return n;
}

int main() {
    int n;
    cin >> n;
    cout << smallestNumber(n) << endl;

    return 0;
}