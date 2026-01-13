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

int main() {
    int n;
    cin >> n;
    cout << hammingWeight(n) << endl;

    return 0;
}
