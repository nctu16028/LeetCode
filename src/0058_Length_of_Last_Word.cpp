#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int sol_candidate, buffer = 0;
    for (const auto& c : s) {
        if (c == ' ') {
            if (buffer > 0)
                sol_candidate = buffer;
            buffer = 0;
        }
        else
            buffer++;
    }
    if (buffer > 0)
        sol_candidate = buffer;

    return sol_candidate;
}

int main() {
    string s;
    getline(cin, s);
    cout << lengthOfLastWord(s) << endl;

    return 0;
}
