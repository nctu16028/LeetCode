#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int ans = 0;
    while (n > 0) {
        ans++;
        n = n & (n - 1);    // to remove the lowest 1
    }

    return ans;
}

int hammingDistance(int x, int y) {
    return hammingWeight(x ^ y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << hammingDistance(x, y) << endl;

    return 0;
}