#include <iostream>
#include <vector>
#include <queue>
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

int coinChange(vector<int>& coins, int amount) {
    vector<int> dpTable(amount + 1, 10001);
    dpTable[0] = 0;
    for (int i = 1; i <= amount; i++) {
        int temp = 10001;
        for (const auto& coin : coins) {
            if (i >= coin)
                temp = min(temp, dpTable[i - coin]);
        }
        dpTable[i] = 1 + temp;
    }

    return (dpTable[amount] > 10000) ? -1 : dpTable[amount];
}

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cin >> amount;
    cout << coinChange(coins, amount) << endl;

    return 0;
}
