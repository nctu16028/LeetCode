#include <iostream>
using namespace std;

int getSum(int a, int b) {
    int generate = a & b;
    int propagate = a ^ b;
    int carry = 0;
    bool ci = 0;
    for (int i = 0; i < 31; i++) {
        bool gi = (generate >> i) & 1;
        bool pi = (propagate >> i) & 1;
        ci = gi | (pi & ci);
        carry |= (ci << (i + 1));
    }

    return propagate ^ carry;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b) << endl;

    return 0;
}