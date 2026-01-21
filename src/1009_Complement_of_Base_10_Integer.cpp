#include <iostream>
using namespace std;

int bitwiseComplement(int n) {
    if (n == 0)
        return 1;

    // Use "bit smearing" to create a mask that filters leading zero bits
    int mask = n;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);
    mask |= (mask >> 16);

    return (~n) & mask;
}

int main() {
    int n;
    cin >> n;
    cout << bitwiseComplement(n) << endl;

    return 0;
}