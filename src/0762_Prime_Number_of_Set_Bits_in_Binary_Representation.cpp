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

int countPrimeSetBits(int left, int right) {
    int output = 0;
    for (int i = left; i <= right; i++) {
        int count = hammingWeight(i);

        // Numbers below 10^6 can contain at most 20 set bits
        if (count == 2 || count == 3 || count == 5 || count == 7 ||
            count == 11 || count == 13 || count == 17 || count == 19) {
            output++;
        }
    }

    return output;
}

int main() {
    int left, right;
    cin >> left >> right;
    cout << countPrimeSetBits(left, right) << endl;

    return 0;
}