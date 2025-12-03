#include <iostream>
using namespace std;

char kthCharacter(int k) {
    // Count the number of 1's in the binary form of k - 1
    int x = k - 1;
    int count = 0;
    while (x) {
        x = x & (x - 1);
        count++;
    }

    return 'a' + count;
}

int main() {
    int k;
    cin >> k;
    cout << kthCharacter(k) << endl;

    return 0;
}
