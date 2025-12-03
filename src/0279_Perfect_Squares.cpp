#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n) {
    vector<int> dpTable(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int temp = dpTable[i - 1];
        for (int j = 2; j * j <= i; j++)
            temp = min(temp, dpTable[i - j * j]);
        dpTable[i] = 1 + temp;
    }

    return dpTable[n];
}

int main() {
    int n;
    cin >> n;
    cout << numSquares(n) << endl;

    return 0;
}
