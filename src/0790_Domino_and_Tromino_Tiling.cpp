#include <iostream>
#include <vector>
using namespace std;

int numTilings(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    vector<int> cumulative_f(n);
    cumulative_f[0] = 1;
    cumulative_f[1] = 2;
    int fi = 2;
    for (int i = 3; i <= n; i++) {
        cumulative_f[i - 1] = (cumulative_f[i - 2] + fi) % 1000000007;
        fi = (cumulative_f[i - 1] + cumulative_f[i - 3]) % 1000000007;
    }

    return fi;
}

int main() {
    int n;
    cin >> n;
    cout << numTilings(n) << endl;

    return 0;
}
