#include <iostream>
using namespace std;

int differenceOfSums(int n, int m) {
    return n * (n + 1) / 2 - m * (n / m) * (n / m + 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << differenceOfSums(n, m) << endl;

    return 0;
}
