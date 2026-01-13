#include <iostream>
#include <string>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    s1 = "_" + s1;
    s2 = "_" + s2;

    // dpTable[i][j] is the edit distance between s1[1..i] and s2[1..j]
    vector<vector<int>> dpTable(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                dpTable[0][j] = dpTable[0][j - 1] + s2[j];  // the edit distance between empty string and s2[1..j] is the cost of deleting j characters from s2
            else if (j == 0)
                dpTable[i][0] = dpTable[i - 1][0] + s1[i];  // the edit distance between s1[1..i] and empty string is the cost of deleting i characters from s1
            else if (s1[i] == s2[j])
                dpTable[i][j] = dpTable[i - 1][j - 1];
            else {
                dpTable[i][j] = min(
                    dpTable[i - 1][j] + s1[i],              // the cost of deleting s1[i] from s1
                    dpTable[i][j - 1] + s2[j]               // the cost of deleting s2[i] from s2
                );
            }
        }
    }

    return dpTable[len1][len2];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << minimumDeleteSum(s1, s2) << endl;

    return 0;
}