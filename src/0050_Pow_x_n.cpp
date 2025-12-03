#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if (n == 0)
        return 1.0;
    else if (n == 1)
        return x;
    else if (n == -1)
        return 1.0 / x;
    else {
        double half_sol = myPow(x, n / 2);
        return half_sol * half_sol * myPow(x, n - (n / 2) * 2);
    }
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;

    return 0;
}
