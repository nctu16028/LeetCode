#include <iostream>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    char ans = '\0';
    for (const auto& c : s)
        ans ^= c;
    for (const auto& c : t)
        ans ^= c;

    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << findTheDifference(s, t) << endl;

    return 0;
}