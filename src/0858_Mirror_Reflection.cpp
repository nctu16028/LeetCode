#include <iostream>
using namespace std;

int mirrorReflection(int p, int q) {
    int gcd_p = p, gcd_q = q;
    while (gcd_q != 0) {
        int temp = gcd_p % gcd_q;
        gcd_p = gcd_q;
        gcd_q = temp;
    }

    p /= gcd_p;
    q /= gcd_p;
    if (q % 2 == 0)
        return 0;
    else if (p % 2 == 1)
        return 1;
    else
        return 2;
}

int main() {
    int p, q;
    cin >> p >> q;
    cout << mirrorReflection(p, q) << endl;

    return 0;
}
