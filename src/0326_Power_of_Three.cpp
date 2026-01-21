#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    for (int i = 1; i < 1162261467; i *= 3) {
        if (n == i)
            return true;
    }
    return (n == 1162261467);
}

int main() {
    int n;
    cin >> n;
    cout << (isPowerOfThree(n) ? "true" : "false") << endl;

    return 0;
}