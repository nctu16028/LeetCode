#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasCommonLetters(const string& s1, const string& s2) {
    int alphabet_mask = 0;  // bit[c - 'a'] is set to 1 if the letter c appears in the string s1
    for (const char& c : s1)
        alphabet_mask |= (1 << (c - 'a'));

    for (const char& c : s2) {
        if (alphabet_mask & (1 << (c - 'a')))
            return true;
    }

    return false;
}

int maxProduct(vector<string>& words) {
    int n = words.size();
    int output = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!hasCommonLetters(words[i], words[j]))
                output = max(output, static_cast<int>(words[i].size() * words[j].size()));
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cout << maxProduct(words) << endl;

    return 0;
}