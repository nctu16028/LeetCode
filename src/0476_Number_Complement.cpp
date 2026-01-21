#include <iostream>
using namespace std;

int findComplement(int num) {
    // Use "bit smearing" to create a mask that filters leading zero bits
    int mask = num;
    mask |= (mask >> 1);
    mask |= (mask >> 2);
    mask |= (mask >> 4);
    mask |= (mask >> 8);
    mask |= (mask >> 16);

    return (~num) & mask;
}

int main() {
    int num;
    cin >> num;
    cout << findComplement(num) << endl;

    return 0;
}