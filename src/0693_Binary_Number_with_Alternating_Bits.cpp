#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
    // Use "bit swearing" to create a mask that filters leading zero bits
    int mask = n;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);
    mask |= (mask >> 16);

    return (n ^ (n >> 1)) == mask;
}

int main() {
    int n;
    cin >> n;
    cout << (hasAlternatingBits(n) ? "true" : "false") << endl;

    return 0;
}