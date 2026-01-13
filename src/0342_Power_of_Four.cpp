#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    for (int i = 0; i <= 30; i += 2) {
        if (n == (1 << i))
            return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << (isPowerOfFour(n) ? "true" : "false") << endl;

    return 0;
}