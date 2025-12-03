#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> buckets;
    for (int i = 0; i < dominoes.size(); i++) {
        int key = (dominoes[i][0] > dominoes[i][1]) ? (10 * dominoes[i][1] + dominoes[i][0]) : (10 * dominoes[i][0] + dominoes[i][1]);
        if (buckets.find(key) == buckets.end())
            buckets.insert({key, 0});
        buckets[key]++;
    }

    int output = 0;
    for (const auto &n : buckets)
        output += (n.second * (n.second - 1) / 2);

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dominoes(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> dominoes[i][0] >> dominoes[i][1];
    cout << numEquivDominoPairs(dominoes) << endl;

    return 0;
}
